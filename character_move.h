#pragma once
#include <stdint.h>
#include "./character.h"

#define CHARACTER_MOVE_SPEED 1

typedef enum	direction_s
{
	E_FORWARD,
	E_BACKWARD,
	E_LEFT,
	E_RIGHT
}							direction_e;

typedef void (*character_move_direction_callback_t)(character_t *target, const direction_e direction);
typedef void (*character_move_callback_t)(character_t *target);

int character_move(character_t *target, const direction_e direction);
int character_move_direction_dispatcher(character_t *c, const direction_e direction,
	character_move_direction_callback_t north_callback,
	character_move_direction_callback_t east_callback,
	character_move_direction_callback_t south_callback,
	character_move_direction_callback_t west_callback,
	character_move_direction_callback_t default_callback);
int character_move_dispatcher(character_t *c, const direction_e direction,
	character_move_callback_t backward_callback,
	character_move_callback_t forward_callback,
	character_move_callback_t left_callback,
	character_move_callback_t right_callback,
	character_move_callback_t default_callback);
