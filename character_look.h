#pragma once
#include "./character.h"

typedef void (*character_look_callback_t)(character_t *target);

int character_look(character_t *target, cardinal_point_e cardinal_point);
int character_look_dispatcher(character_t *c, const cardinal_point_e direction,
	character_look_callback_t forward_callback,
	character_look_callback_t backward_callback,
	character_look_callback_t left_callback,
	character_look_callback_t right_callback);
