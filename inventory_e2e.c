#include <assert.h>
#include "not_rp1.h"

void					e2e_inventory()
{
	item_t			g1 = {0, E_GUN, {0, 0}};
	item_t			g2 = {1, E_GUN, {1, 1}};
	item_t			g3 = {2, E_GUN, {2, 2}};
	item_t 			k1 = {3, E_KEY, {5, 0}};
	item_t 			k2 = {4, E_KEY, {1, 4}};
	item_t 			n1 = {5, E_KNIFE, {3, 2}};
	inventory_t	*i = NULL;

	if ((i = new_inventory())) {
		assert(i->size == 0);
		add_to_inventory(i, &g3);
		add_to_inventory(i, &n1);
		add_to_inventory(i, &k1);
		assert(i->size == 3);
		add_to_inventory(i, &g1);
		add_to_inventory(i, &g2);
		add_to_inventory(i, &k2);
		assert(i->size == 6);
		remove_from_inventory(i, 5);
		assert(i->size == 5);
		remove_from_inventory(i, 5);
		assert(i->size == 5);
		item_t *fg = find_first_in_inventory(i, E_GUN);
		assert(fg->id == 1 && fg->type == E_GUN);
		remove_from_inventory(i, fg->id);
		assert(i->size == 4);
		item_t *i5 = find_in_inventory(i, 5);
		assert(i5 == NULL);
		item_t *fn = find_first_in_inventory(i, E_KNIFE);
		assert(fn == NULL);
		item_t *i0 = remove_from_inventory(i, 0);
		assert(i0->id == 0 && i0->type == E_GUN);
		clear_inventory(i);
		assert(i->size == 0);
		delete_inventory(i);
	} else {
		exit(EXIT_FAILURE);
	}
}
