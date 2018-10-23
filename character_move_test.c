#include <assert.h>
#include "./character_move.h"
#include "./character_look.h"
#include "./character.h"
#include "./character_mock.h"

void create(character_t *c);
void move_north_backward(character_t *c);
void move_north_forward(character_t *c);
void move_north_right(character_t *c);
void move_north_left(character_t *c);
void move_south_backward(character_t *c);
void move_south_forward(character_t *c);
void move_south_left(character_t *c);
void move_south_right(character_t *c);
void move_east_backward(character_t *c);
void move_east_forward(character_t *c);
void move_east_left(character_t *c);
void move_east_right(character_t *c);
void move_west_backward(character_t *c);
void move_west_forward(character_t *c);
void move_west_left(character_t *c);
void move_west_right(character_t *c);

void describe_movement()
{
	character_should((char *)"move north backward", move_north_backward);
	character_should((char *)"move north forward", move_north_forward);
	character_should((char *)"move north left", move_north_left);
	character_should((char *)"move north right", move_north_right);

	character_should((char *)"move south backward", move_south_backward);
	character_should((char *)"move south forward", move_south_forward);
	character_should((char *)"move south left", move_south_left);
	character_should((char *)"move south right", move_south_right);

	character_should((char *)"move east backward", move_east_backward);
	character_should((char *)"move east forward", move_east_forward);
	character_should((char *)"move east left", move_east_left);
	character_should((char *)"move east right", move_east_right);

	character_should((char *)"move west backward", move_west_backward);
	character_should((char *)"move west forward", move_west_forward);
	character_should((char *)"move west left", move_west_left);
	character_should((char *)"move west right", move_west_right);
}

inline void move_north_backward(character_t *c)
{
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 1);
}

inline void move_north_forward(character_t *c)
{
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
}

inline void move_north_right(character_t *c)
{
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
}

inline void move_north_left(character_t *c)
{
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == -1 && c->coord[E_Y] == 0);
}

inline void move_south_backward(character_t *c)
{
	character_look(c, E_SOUTH);
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
}

inline void move_south_forward(character_t *c)
{
	character_look(c, E_SOUTH);
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 1);
}

inline void move_south_left(character_t *c)
{
	character_look(c, E_SOUTH);
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == -1 && c->coord[E_Y] == 0);
}

inline void move_south_right(character_t *c)
{
	character_look(c, E_SOUTH);
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
}

inline void move_east_backward(character_t *c)
{
	character_look(c, E_EAST);
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == -1 && c->coord[E_Y] == 0);
}

inline void move_east_forward(character_t *c)
{
	character_look(c, E_EAST);
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
}

inline void move_east_left(character_t *c)
{
	character_look(c, E_EAST);
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 1);
}

inline void move_east_right(character_t *c)
{
	character_look(c, E_EAST);
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
}

inline void move_west_backward(character_t *c)
{
	character_look(c, E_WEST);
	character_move(c, E_BACKWARD);
	assert(c->coord[E_X] == -1 && c->coord[E_Y] == 0);
}

inline void move_west_forward(character_t *c)
{
	character_look(c, E_WEST);
	character_move(c, E_FORWARD);
	assert(c->coord[E_X] == 1 && c->coord[E_Y] == 0);
}

inline void move_west_left(character_t *c)
{
	character_look(c, E_WEST);
	character_move(c, E_LEFT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 1);
}

inline void move_west_right(character_t *c)
{
	character_look(c, E_WEST);
	character_move(c, E_RIGHT);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == -1);
}
