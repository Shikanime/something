#pragma once
#include <stdint.h>
#include "./globa.h"
#include "./coord.h"

typedef enum	cardinal_point_e {
	E_NORTH = 0,
	E_EAST = 90,
	E_SOUTH = 180,
	E_WEST = 270
}							cardinal_point_e;

typedef enum	character_type_s {
	E_PLAYER,
	E_GUARD,
	E_CAMERA,
	E_DOG
}							character_type_e;


typedef struct			character_s
{
	uint32_t					id;
	character_type_e	type;
	int32_t						coord[DIMENSIONS];
	cardinal_point_e	azimuth;
}										character_t;

character_t *new_character(const uint32_t id, const int32_t x, const int32_t y, const character_type_e t);
void delete_character(character_t *c);
void print_character_id(character_t *c);
void print_character_coord_x(character_t *c);
void print_character_coord_y(character_t *c);
void print_character_azimut(character_t *c);
