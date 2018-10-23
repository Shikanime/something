#include <stdlib.h>
#include <unistd.h>
#include "./character.h"
#include "./helper.h"

inline character_t	*new_character(const int id, const int x, const int y, const character_type_e t, const cardinal_point_e p)
{
	character_t				*c = NULL;

	c = (character_t *)calloc(1, sizeof(character_t));
	c->id = id;
	c->coord[E_X] = x;
	c->coord[E_Y] = y;
	c->azimuth = p;
	c->type = t;
	return c;
}

inline void delete_character(character_t *c)
{
	free(c);
}

void print_character_id(character_t *c)
{
	print_integer(c->id);
}

void print_character_coord_x(character_t *c)
{
	print_integer(c->coord[E_X]);
}

void print_character_coord_y(character_t *c)
{
	print_integer(c->coord[E_Y]);
}

void print_character_azimut(character_t *c)
{
	print_integer(c->azimuth);
}
