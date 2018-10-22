#include <assert.h>
#include "./inventory_test.h"
#include "./inventory_mock.h"
#include "./inventory.h"
#include "./helper.h"

void add_element(inventory_t *i);
void remove_element(inventory_t *i);

void describe_inventory() {
	inventory_should((uint8_t *) "Inventory should add element", add_element);
	inventory_should((uint8_t *) "Inventory should remove element", remove_element);
}

void			add_element(inventory_t *i) {
	assert(987 == i->first->item->id);
	assert(25 == i->first->next->item->id);
	assert(864 == i->first->next->next->item->id);
	assert(735 == i->first->next->next->next->item->id);
	assert(735 == i->first->next->next->next->next->precedent->item->id);
	assert(864 == i->first->next->next->next->next->precedent->precedent->item->id);
	assert(25 == i->first->next->next->next->next->precedent->precedent->precedent->item->id);
	assert(987 == i->first->next->next->next->next->precedent->precedent->precedent->precedent->item->id);
}

void remove_element(inventory_t *i) {
	remove_from_inventory(i, 987);
	assert(25 == i->first->item->id);
	remove_from_inventory(i, 25);
	assert(864 == i->first->item->id);
	remove_from_inventory(i, 735);
	assert(33 == i->first->next->item->id);
	assert(96 == i->first->next->next->item->id);
}

void e2e_inventory() {
	item_t gun1 = {0, E_GUN, {0, 0}};
	item_t gun2 = {1, E_GUN, {1, 1}};
	item_t gun3 = {2, E_GUN, {2, 2}};
	item_t key1 = {3, E_KEY, {5, 0}};
	item_t key2 = {4, E_KEY, {1, 4}};
	item_t knife1 = {5, E_KNIFE, {3, 2}};
	inventory_t *inventory = new_inventory();

	if (inventory) {
			print_string((uint8_t *) "--- empty list ---\n");
			print_inventory(inventory);
			add_to_inventory(inventory, &gun3);
			add_to_inventory(inventory, &knife1);
			add_to_inventory(inventory, &key1);
			print_string((uint8_t *) "--- list of size 3 ---\n");
			print_inventory(inventory);
			add_to_inventory(inventory, &gun1);
			add_to_inventory(inventory, &gun2);
			add_to_inventory(inventory, &key2);
			print_string((uint8_t *) "--- list of size 6 ---\n");
			print_inventory(inventory);
			remove_from_inventory(inventory, 5);
			print_string((uint8_t *) "--- remove knife of id 5 ---");
			print_inventory(inventory);
			remove_from_inventory(inventory, 5);
			print_string((uint8_t *) "--- remove first gun found ---\n");
			print_inventory(inventory);
			item_t *first_gun = find_first_in_inventory(inventory, E_GUN);
			remove_from_inventory(inventory, (int32_t) first_gun->id);
			print_string((uint8_t *) "--- search knife 5 ---\n");
			print_inventory(inventory);
			item_t *item_5 = find_in_inventory(inventory, 5);
			if (!item_5) {
				print_string((uint8_t *) "no item of id 5 found\n");
			}
			print_string((uint8_t *) "--- search first knife ---\n");
			item_t *first_knife = find_first_in_inventory(inventory, E_KNIFE);
			if (!first_knife) {
				print_string((uint8_t *) "no knife found\n");
			}
			item_t *item_0 = remove_from_inventory(inventory, 0);
			print_string((uint8_t *) "--- retrieve item 0 after removing it ---\n");
			if (!item_0) {
				print_string((uint8_t *) "no item of id 0 to remove\n");
			}
			clear_inventory(inventory);
	}
}
