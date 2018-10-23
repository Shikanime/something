#pragma once
#include <stdlib.h>
#include <stdint.h>
#include "./globa.h"

typedef enum	item_type_s
{
	E_KEY,
	E_DOOR,
	E_GUN,
	E_KNIFE
} 						item_type_e;

typedef struct	item_s
{
	int 					id;
	item_type_e		type;
	int						coord[DIMENSIONS];
}								item_t;

typedef struct								inventory_element_s
{
	item_t											*item;
	struct inventory_element_s	*next;
	struct inventory_element_s	*precedent;
}															inventory_element_t;

typedef struct				inventory_s
{
	inventory_element_t	*first;
	inventory_element_t	*last;
	size_t							size;
}											inventory_t;

inventory_t *new_inventory();
item_t *new_item(const int id, const int x, const int y, const item_type_e t);
void delete_inventory(inventory_t *i);
void clear_inventory(inventory_t *i);
void add_to_inventory(inventory_t *i, item_t *);
item_t *remove_from_inventory(inventory_t *i, int id);
item_t *find_in_inventory(inventory_t *i, int id);
item_t *find_first_in_inventory(inventory_t *i, item_type_e t);
void print_inventory(inventory_t *i);
void print_item(item_t *d);
