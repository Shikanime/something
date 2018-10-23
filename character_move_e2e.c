#include <assert.h>
#include "not_rp1.h"

void 					e2e_character_move()
{
	character_t	player = {0, E_PLAYER, E_NULL_ORIENTATION, {5, 5}};

	assert(player.coord[E_X] == 5);
	assert(player.coord[E_Y] == 5);
	character_move(&player, E_FORWARD);
	assert(player.coord[E_X] == 5);
	assert(player.coord[E_Y] == 4);
	character_move(&player, E_LEFT);
	assert(player.coord[E_X] == 4);
	assert(player.coord[E_Y] == 4);
	character_move(&player, E_BACKWARD);
	assert(player.coord[E_X] == 4);
	assert(player.coord[E_Y] == 5);
	character_move(&player, E_RIGHT);
	assert(player.coord[E_X] == 5);
	assert(player.coord[E_Y] == 5);
}
