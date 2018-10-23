#include <assert.h>
#include "not_rp1.h"

void 					e2e_character_look()
{
	character_t player = {2, E_PLAYER, E_NORTH, {5, 5}};

	assert(player.azimuth == 0);
	character_look(&player, E_NORTH);
	assert(player.azimuth == 0);
	character_look(&player, E_SOUTH);
	assert(player.azimuth == 180);
	character_look(&player, E_WEST);
	assert(player.azimuth == 270);
	character_look(&player, E_EAST);
	assert(player.azimuth == 90);
}
