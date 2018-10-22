#include <stdlib.h>
#include <stdbool.h>
#include "./inventory.h"
#include "./helper.h"
#include "./coord.h"

void delete_inventory_elements(inventory_t *i);
void delete_element(inventory_element_t *e);
inventory_element_t *inventory_extract_element(inventory_t *i);

inventory_t 	*new_inventory() {
	inventory_t	*i = NULL;

	i = (inventory_t *) calloc(1, sizeof(inventory_t));
	i->first = 0;
	i->last = 0;
	i->size = 0;
	return i;
}

void delete_inventory(inventory_t *i) {
	delete_inventory_elements(i);
	free(i);
}

item_t 		*new_item(const uint32_t id, const int32_t x, const int32_t y, const item_type_e t) {
	item_t	*d = NULL;

	d = (item_t *) calloc(1, sizeof(item_t));
	d->id = id;
	d->type = t;
	d->coord[E_X] = x;
	d->coord[E_Y] = y;
	return d;
}

void delete_element(inventory_element_t *e) {
	free(e);
}

void clear_inventory(inventory_t *i) {
	delete_inventory_elements(i);
}

void									add_to_inventory(inventory_t *i, item_t *d) {
	inventory_element_t	*e = NULL;

	e = (inventory_element_t *) calloc(1, sizeof(inventory_element_t));
	e->item = d;
	e->next = NULL;
	e->precedent = NULL;
	if (i->size == 0) {
		i->last = e;
	} else {
		e->next = i->first;
		e->next->precedent = e;
	}
	i->first = e;
	i->size++;
}

item_t								*remove_from_inventory(inventory_t *i, int id) {
	if (i->size != 0) {
		for (inventory_element_t *e = i->first; e != NULL; e = e->next) {
			if (e->item->id == (uint32_t) id) {
				if (e->precedent != NULL) {
					e->precedent->next = e->next;
				} else {
					i->first = e->next;
				}
				if (e->next != NULL) {
					e->next->precedent = e->precedent;
				} else {
					e->next->precedent = NULL;
				}
				i->size--;
				if (i->size == 0) {
					i->last = NULL;
				}
				delete_element(e);
				return e->item;
			}
		}
	}
	return NULL;
}

item_t *find_in_inventory(inventory_t *i, int id) {
	if (i->size != 0) {
		for (inventory_element_t *e = i->first; e != NULL; e = e->next) {
			if (e->item->id == (uint32_t) id) {
				delete_element(e);
				return e->item;
			}
		}
	}
	return NULL;
}

item_t *find_first_in_inventory(inventory_t *i, item_type_e t) {
	if (i->size != 0) {
		for (inventory_element_t *e = i->first; e != NULL; e = e->next) {
			if (e->item->type == t) {
				return e->item;
			}
		}
	}
	return NULL;
}

void print_inventory(inventory_t *i) {
	if (i->size != 0) {
		for (inventory_element_t *e = i->first; e != NULL; e = e->next) {
			print_item(e->item);
		}
	}
}

void print_item(item_t *d) {
	print_string((uint8_t *) "id : [");
	print_integer((int32_t) d->id);
	print_string((uint8_t *) "] ");

	switch (d->type)
	{
		case E_DOOR:
			print_string((uint8_t *) "door");
			break;
		case E_GUN:
			print_string((uint8_t *) "gun");
			break;
		case E_KEY:
			print_string((uint8_t *) "key");
			break;
		case E_KNIFE:
			print_string((uint8_t *) "kniffe");
			break;
		default:
			break;
	}
	print_character((uint8_t) '\n');
}

void delete_inventory_elements(inventory_t *i) {
	while (i->size != 0) {
		free(inventory_extract_element(i));
	}
}

inventory_element_t		*inventory_extract_element(inventory_t * i) {
	inventory_element_t	*e = NULL;

	if (i->size != 0) {
		e = i->first;
		i->first = e->next;
		e->next = NULL;
		i->size--;
		if (i->size == 0) {
			i->last = NULL;
		}
	}
	return e;
}
