#include <stdlib.h>
#include "./character_mock.h"
#include "./helper.h"

void do_character_should(void (*test)(character_t *c));

inline void character_should(const char *s, void (*test)(character_t *c))
{
	print_string((char *)"[START] - Character should ");
	print_string((char *)s);
	print_character('\n');
	do_character_should(test);
	print_string((char *)"[END] - Character should ");
	print_string((char *)s);
	print_string((char *)"\n\n");
}

inline void do_character_should(void (*test)(character_t *c))
{
	character_t *c = NULL;

	c = new_character(453, 0, 0, E_PLAYER, E_NORTH);
	test(c);
	delete_character(c);
}
