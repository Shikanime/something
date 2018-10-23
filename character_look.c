#include <stdlib.h>
#include "./character_look.h"
#include "./helper.h"

void do_character_look_north(character_t *target);
void do_character_look_east(character_t *target);
void do_character_look_south(character_t *target);
void do_character_look_west(character_t *target);

int character_look(character_t *target, cardinal_point_e cardinal_point)
{
	return character_look_dispatcher(target, cardinal_point,
		do_character_look_north,
		do_character_look_east,
		do_character_look_south,
		do_character_look_west);
}

int character_look_dispatcher(character_t *c, cardinal_point_e cardinal_point,
	character_look_callback_t north_callback,
	character_look_callback_t east_callback,
	character_look_callback_t south_callback,
	character_look_callback_t west_callback) {
	switch (cardinal_point)
	{
	case E_NORTH:
		north_callback(c);
		return EXIT_SUCCESS;
	case E_EAST:
		east_callback(c);
		return EXIT_SUCCESS;
	case E_SOUTH:
		south_callback(c);
		return EXIT_SUCCESS;
	case E_WEST:
		west_callback(c);
		return EXIT_SUCCESS;
	default:
		return EXIT_FAILURE;
	}
}

void do_character_look_north(character_t *target)
{
	target->azimuth = E_NORTH;
	print_string((char *)"id : [");
	print_character_id(target);
	print_string((char *)"] look north.\n");
}

void do_character_look_east(character_t *target)
{
	target->azimuth = E_EAST;
	print_string((char *)"id : [");
	print_character_id(target);
	print_string((char *)"] look east.\n");
}

void do_character_look_south(character_t *target)
{
	target->azimuth = E_SOUTH;
	print_string((char *)"id : [");
	print_character_id(target);
	print_string((char *)"] look south.\n");
}

void do_character_look_west(character_t *target)
{
	target->azimuth = E_WEST;
	print_string((char *)"id : [");
	print_character_id(target);
	print_string((char *)"] look west.\n");
}
