#include <stdlib.h>
#include "./helper.h"
#include "./character_move.h"
#include "./character_look.h"

void do_character_move_north(character_t *c, const direction_e d);
void do_character_move_east(character_t *c, const direction_e d);
void do_character_move_south(character_t *c, const direction_e d);
void do_character_move_west(character_t *c, const direction_e d);
void character_move_backward(character_t *c);
void character_move_forward(character_t *c);
void character_move_left(character_t *c);
void character_move_right(character_t *c);

int character_move(character_t *target, const direction_e direction)
{
	return character_move_direction_dispatcher(target, direction,
		do_character_move_north,
		do_character_move_south,
		do_character_move_east,
		do_character_move_west,
		do_character_move_north);
}

int character_move_direction_dispatcher(character_t *c, const direction_e d,
	character_move_direction_callback_t north_callback,
	character_move_direction_callback_t south_callback,
	character_move_direction_callback_t east_callback,
	character_move_direction_callback_t west_callback,
	character_move_direction_callback_t default_callback) {
	switch (c->azimuth)
	{
	case E_NORTH:
		north_callback(c, d);
		return EXIT_SUCCESS;
	case E_SOUTH:
		south_callback(c, d);
		return EXIT_SUCCESS;
	case E_EAST:
		east_callback(c, d);
		return EXIT_SUCCESS;
	case E_WEST:
		west_callback(c, d);
		return EXIT_SUCCESS;
	default:
		default_callback(c, d);
		return EXIT_SUCCESS;
	}
}

int character_move_dispatcher(character_t *c, const direction_e d,
	character_move_callback_t forward_callback,
	character_move_callback_t backward_callback,
	character_move_callback_t left_callback,
	character_move_callback_t right_callback,
	character_move_callback_t default_callback) {
	switch (d)
	{
	case E_FORWARD:
		forward_callback(c);
		return EXIT_SUCCESS;
	case E_BACKWARD:
		backward_callback(c);
		return EXIT_SUCCESS;
	case E_LEFT:
		left_callback(c);
		return EXIT_SUCCESS;
	case E_RIGHT:
		right_callback(c);
		return EXIT_SUCCESS;
	default:
		default_callback(c);
		return EXIT_SUCCESS;
	}
}

inline void do_character_move_north(character_t *c, const direction_e d)
{
	character_move_dispatcher(c, d,
		character_move_forward,
		character_move_backward,
		character_move_left,
		character_move_right,
		character_move_backward);
}

inline void do_character_move_south(character_t *c, const direction_e d)
{
	character_move_dispatcher(c, d,
		character_move_backward,
		character_move_forward,
		character_move_left,
		character_move_right,
		character_move_backward);
}

inline void do_character_move_east(character_t *c, const direction_e d)
{
	character_move_dispatcher(c, d,
		character_move_right,
		character_move_left,
		character_move_backward,
		character_move_forward,
		character_move_right);
}

inline void do_character_move_west(character_t *c, const direction_e d)
{
	character_move_dispatcher(c, d,
		character_move_right,
		character_move_left,
		character_move_backward,
		character_move_forward,
		character_move_left);
}

inline void character_move_backward(character_t *c) {
	c->coord[E_Y] += CHARACTER_MOVE_SPEED;
	print_string("id : [");
	print_character_id(c);
	print_string("] moves backward.\n");
}

inline void character_move_forward(character_t *c) {
	c->coord[E_Y] -= CHARACTER_MOVE_SPEED;
	print_string("id : [");
	print_character_id(c);
	print_string("] moves forward.\n");
}

inline void character_move_left(character_t *c) {
	c->coord[E_X] -= CHARACTER_MOVE_SPEED;
	print_string("id : [");
	print_character_id(c);
	print_string("] moves left.\n");
}

inline void character_move_right(character_t *c) {
	c->coord[E_X] += CHARACTER_MOVE_SPEED;
	print_string("id : [");
	print_character_id(c);
	print_string("] moves right.\n");
}
