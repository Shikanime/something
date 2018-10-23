#pragma once
#include <stdint.h>
#include "./globa.h"
#include "./coord.h"

typedef enum	cardinal_point_s
{
	E_NULL_ORIENTATION = -1,
	E_NORTH = 0,
	E_EAST = 90,
	E_SOUTH = 180,
	E_WEST = 270
} 						cardinal_point_e;

typedef enum	character_type_s
{
	E_NULL_TYPE = -1,
	E_PLAYER,
	E_GUARD,
	E_CAMERA,
	E_DOG
}							character_type_e;

typedef struct			character_s
{
	int								id;
	character_type_e	type;
	cardinal_point_e	azimuth;
	int 							coord[DIMENSIONS];
}										character_t;

character_t *new_character(const int id, const int x, const int y, const character_type_e t, const cardinal_point_e c);
void delete_character(character_t *c);
void print_character_id(character_t *c);
void print_character_coord_x(character_t *c);
void print_character_coord_y(character_t *c);
void print_character_azimut(character_t *c);
