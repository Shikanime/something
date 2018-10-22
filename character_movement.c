#include <stdlib.h>
#include "./helper.h"
#include "./character_movement.h"

void do_character_backward_move(character_t *target);
void do_character_forward_move(character_t *target);
void do_character_left_move(character_t *target);
void do_character_right_move(character_t *target);

int character_move(character_t *target, const direction_e direction) {
	switch (direction)
	{
		case E_BACKWARD:
			do_character_backward_move(target);
			return EXIT_SUCCESS;
		case E_FORWARD:
			do_character_forward_move(target);
			return EXIT_SUCCESS;
		case E_LEFT:
			do_character_left_move(target);
			return EXIT_SUCCESS;
		case E_RIGHT:
			do_character_right_move(target);
			return EXIT_SUCCESS;
		default:
			return EXIT_FAILURE;
	}
}

inline void do_character_backward_move(character_t *target) {
	target->coord[E_X] -= CHARACTER_MOVE_SPEED;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] moves backward.\n");
}

inline void do_character_forward_move(character_t *target) {
	target->coord[E_X] += CHARACTER_MOVE_SPEED;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] moves forward.\n");
}

inline void do_character_left_move(character_t *target) {
	target->coord[E_Y] -= CHARACTER_MOVE_SPEED;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] moves left.\n");
}

inline void do_character_right_move(character_t *target) {
	target->coord[E_Y] += CHARACTER_MOVE_SPEED;
	print_string((uint8_t *) "id : [");
	print_character_id(target);
	print_string((uint8_t *) "] moves right.\n");
}
