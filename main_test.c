#include <stdlib.h>
#include "./character_test.h"
#include "./character_move_test.h"
#include "./character_look_test.h"
#include "./inventory_test.h"
#include "./inventory_e2e.h"
#include "./character_move_e2e.h"
#include "./character_look_e2e.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	describe_character();
	describe_movement();
	describe_look();
	describe_inventory();
	e2e_character_move();
	e2e_character_look();
	e2e_inventory();
	return EXIT_SUCCESS;
}
