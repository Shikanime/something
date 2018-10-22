#include <stdlib.h>
#include "./character_mock.h"
#include "./helper.h"

inline void		character_should(const uint8_t *s, void (*test)(character_t *c)) {
	character_t	*c = NULL;

	print_string((uint8_t *) "[START] - Character should ");
	print_string((uint8_t *) s);
	print_character((uint8_t) '\n');
	c = new_character(453, 0, 0, E_PLAYER);
	test(c);
	delete_character(c);
	print_string((uint8_t *) "[END] - Character should ");
	print_string((uint8_t *) s);
	print_string((uint8_t *) "\n\n");
}
