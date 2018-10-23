#include <stdlib.h>
#include "./character_test.h"
#include "./character_move_test.h"
#include "./character_look_test.h"
#include "./inventory_test.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	describe_character();
	describe_move();
	describe_look();
	describe_inventory();
	return EXIT_SUCCESS;
}
