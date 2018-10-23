#include "not_rp1.h"
#include "./helper.h"

void			e2e_inventory()
{
	item_t			gun1 = {0, E_GUN, {0, 0}};
	item_t			gun2 = {1, E_GUN, {1, 1}};
	item_t			gun3 = {2, E_GUN, {2, 2}};
	item_t 			key1 = {3, E_KEY, {5, 0}};
	item_t 			key2 = {4, E_KEY, {1, 4}};
	item_t 			knife1 = {5, E_KNIFE, {3, 2}};
	inventory_t	*inventory = new_inventory();

	print_string("--- empty list ---\n");
	print_inventory(inventory);
	add_to_inventory(inventory, &gun3);
	add_to_inventory(inventory, &knife1);
	add_to_inventory(inventory, &key1);
	print_string("--- list of size 3 ---\n");
	print_inventory(inventory);
	add_to_inventory(inventory, &gun1);
	add_to_inventory(inventory, &gun2);
	add_to_inventory(inventory, &key2);
	print_string("--- list of size 6 ---\n");
	print_inventory(inventory);
	remove_from_inventory(inventory, 5);
	print_string("--- remove knife of id 5 ---\n");
	print_inventory(inventory);
	remove_from_inventory(inventory, 5);
	print_string("--- remove first gun found ---\n");
	print_inventory(inventory);
	item_t *first_gun = find_first_in_inventory(inventory, E_GUN);
	remove_from_inventory(inventory, first_gun->id);
	print_string("--- search knife 5 ---\n");
	print_inventory(inventory);
	item_t *item_5 = find_in_inventory(inventory, 5);
	if (!item_5)
	{
		print_string("no item of id 5 found\n");
	}
	print_string("--- search first knife ---\n");
	item_t *first_knife = find_first_in_inventory(inventory, E_KNIFE);
	if (!first_knife)
	{
		print_string("no knife found\n");
	}
	item_t *item_0 = remove_from_inventory(inventory, 0);
	print_string("--- retrieve item 0 after removing it ---\n");
	if (!item_0)
	{
		print_string("no item of id 0 to remove\n");
	}
	clear_inventory(inventory);
}
