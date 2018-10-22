#include <stdlib.h>
#include <unistd.h>
#include "./character.h"
#include "./helper.h"

inline character_t *new_character(const uint32_t id, const int32_t x, const int32_t y, const character_type_e t) {
	character_t *c = NULL;

	c = (character_t *)calloc(1, sizeof(character_t));
	c->id = id;
	c->coord[E_X] = x;
	c->coord[E_Y] = y;
	c->type = t;
	return c;
}

inline void delete_character(character_t *c) {
	free(c);
}

void print_character_id(character_t *c) {
	print_integer((int32_t) c->id);
}

void print_character_coord_x(character_t *c) {
	print_integer(c->coord[E_X]);
}

void print_character_coord_y(character_t *c) {
	print_integer(c->coord[E_Y]);
}

void print_character_azimut(character_t *c) {
	print_integer(c->azimuth);
}
