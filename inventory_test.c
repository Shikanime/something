#include <assert.h>
#include "./inventory_test.h"
#include "./inventory_mock.h"
#include "./inventory.h"

void add_element(inventory_t *i);
void remove_element(inventory_t *i);

void describe_inventory()
{
	inventory_should("Inventory should add element", add_element);
	inventory_should("Inventory should remove element", remove_element);
}

void add_element(inventory_t *i)
{
	assert(987 == i->first->item->id);
	assert(25 == i->first->next->item->id);
	assert(864 == i->first->next->next->item->id);
	assert(735 == i->first->next->next->next->item->id);
	assert(735 == i->first->next->next->next->next->precedent->item->id);
	assert(864 == i->first->next->next->next->next->precedent->precedent->item->id);
	assert(25 == i->first->next->next->next->next->precedent->precedent->precedent->item->id);
	assert(987 == i->first->next->next->next->next->precedent->precedent->precedent->precedent->item->id);
}

void remove_element(inventory_t *i)
{
	remove_from_inventory(i, 987);
	assert(25 == i->first->item->id);
	remove_from_inventory(i, 25);
	assert(864 == i->first->item->id);
	remove_from_inventory(i, 735);
	assert(33 == i->first->next->item->id);
	assert(96 == i->first->next->next->item->id);
}
