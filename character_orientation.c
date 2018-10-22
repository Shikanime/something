#include <stdlib.h>
#include "./character_orientation.h"
#include "./helper.h"

void do_character_look_north(character_t *target);
void do_character_look_east(character_t *target);
void do_character_look_south(character_t *target);
void do_character_look_west(character_t *target);

int character_look(character_t *target, cardinal_point_e cardinal_point) {
	switch (cardinal_point)
	{
		case E_NORTH:
			do_character_look_north(target);
			return EXIT_SUCCESS;
		case E_EAST:
			do_character_look_east(target);
			return EXIT_SUCCESS;
		case E_SOUTH:
			do_character_look_south(target);
			return EXIT_SUCCESS;
		case E_WEST:
			do_character_look_west(target);
			return EXIT_SUCCESS;
		default:
			return EXIT_FAILURE;
	}
}

void do_character_look_north(character_t *target) {
	target->azimuth = E_NORTH;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] look north.\n");
}

void do_character_look_east(character_t *target) {
	target->azimuth = E_EAST;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] look east.\n");
}

void do_character_look_south(character_t *target) {
	target->azimuth = E_SOUTH;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] look south.\n");
}

void do_character_look_west(character_t *target) {
	target->azimuth = E_WEST;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] look west.\n");
}
