#include <assert.h>
#include "./character_look_test.h"
#include "./character_look.h"
#include "./character_mock.h"

void look_north(character_t *c);
void look_east(character_t *c);
void look_south(character_t *c);
void look_west(character_t *c);
void look(character_t *c);

void describe_look()
{
	character_should("look north", look_north);
	character_should("look east", look_east);
	character_should("look south", look_south);
	character_should("look west", look_west);
	character_should("look", look);
}

inline void look_north(character_t *c)
{
	character_look(c, E_NORTH);
	assert(c->azimuth == E_NORTH);
}

inline void look_east(character_t *c)
{
	character_look(c, E_EAST);
	assert(c->azimuth == E_EAST);
}

inline void look_south(character_t *c)
{
	character_look(c, E_SOUTH);
	assert(c->azimuth == E_SOUTH);
}

inline void look_west(character_t *c)
{
	character_look(c, E_WEST);
	assert(c->azimuth == E_WEST);
}

inline void look(character_t *c)
{
	character_look(c, E_NORTH);
	character_look(c, E_SOUTH);
	character_look(c, E_WEST);
	character_look(c, E_EAST);
}
