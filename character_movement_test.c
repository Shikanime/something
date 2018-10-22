#include <assert.h>
#include "./character_movement.h"
#include "./character.h"
#include "./character_mock.h"

void create(character_t	*c);
void move_backward();
void move_forward();
void move_right();
void move_left();
void move(character_t	*c);

void describe_movement()
{
	character_should((uint8_t *) "move backward", move_backward);
	character_should((uint8_t *) "move forward", move_forward);
	character_should((uint8_t *) "move left", move_left);
	character_should((uint8_t *) "move right", move_right);
	character_should((uint8_t *) "move", move);
}

inline void move(character_t	*c) {
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == -1);
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 0);
}

inline void move_backward(character_t	*c) {
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == -1 && c->coord[E_Y] == 0);
}

inline void move_forward(character_t	*c) {
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
}

inline void move_right(character_t	*c) {
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 1);
}

inline void move_left(character_t	*c) {
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
}
