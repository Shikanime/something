#include <assert.h>
#include "./character_test.h"
#include "./character_mock.h"

void create(character_t	*c);

void describe_character() {
	character_should((uint8_t *) "create", create);
}

inline void create(character_t	*c) {
	assert(c->id == 453);
	assert(c->coord[E_X] == 0 && c->coord[E_Y] == 0);
	assert(c->type == E_PLAYER);
}
