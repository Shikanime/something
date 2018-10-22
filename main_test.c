#include <stdlib.h>
#include "./character_test.h"
#include "./character_movement_test.h"
#include "./character_orientation_test.h"
#include "./inventory_test.h"

int main(int argc, char const *argv[]) {
	(void) argc;
	(void) argv;

	describe_character();
	describe_movement();
	describe_look();
	describe_inventory();
	e2e_inventory();
	return EXIT_SUCCESS;
}
