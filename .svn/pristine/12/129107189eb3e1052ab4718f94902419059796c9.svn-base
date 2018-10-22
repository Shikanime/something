#include "./inventory_mock.h"
#include "./helper.h"

inline void		inventory_should(const uint8_t *s, void (*test)(inventory_t *i)) {
	inventory_t	*i = NULL;
	item_t	*gun = NULL;
	item_t	*door = NULL;
	item_t	*key = NULL;
	item_t	*kniffe = NULL;

	print_string((uint8_t *) "[START] - ");
	print_string((uint8_t *) s);
	print_character((uint8_t) '\n');
	i = new_inventory();
	door = new_item(634, 0, 0, E_DOOR);
	gun = new_item(135, 0, 0, E_GUN);
	key = new_item(96, 0, 0, E_KEY);
	kniffe = new_item(33, 0, 0, E_KNIFE);
	add_to_inventory(i, door);
	add_to_inventory(i, gun);
	add_to_inventory(i, key);
	add_to_inventory(i, kniffe);
	door = new_item(735, 0, 0, E_DOOR);
	gun = new_item(864, 0, 0, E_GUN);
	key = new_item(25, 0, 0, E_KEY);
	kniffe = new_item(987, 0, 0, E_KNIFE);
	add_to_inventory(i, door);
	add_to_inventory(i, gun);
	add_to_inventory(i, key);
	add_to_inventory(i, kniffe);
	test(i);
	delete_inventory(i);
	print_string((uint8_t *) "[END] - ");
	print_string((uint8_t *) s);
	print_string((uint8_t *) "\n\n");
}
