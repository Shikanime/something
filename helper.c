#include "./helper.h"

void	print_character(const uint8_t c) {
  write(1, &c, 1);
}

void	print_string(const uint8_t s[]) {
  for (size_t i = 0; s[i]; ++i) {
		print_character(s[i]);
	}
}

void print_integer(int32_t n) {
	int32_t b = 0;

	if (n == (int32_t) -2147483648) {
		print_string((uint8_t *) "-2147483648");
	} else {
		if (n < 0) {
			print_character('-');
			n *= (int32_t) -1;
		}
		if (n < 10) {
			print_character((uint8_t) (n + 48));
		} else {
			b = 1;
			while (b <= (n / 10)) {
				b *= 10;
			}
			while (b >= 1) {
				print_character((uint8_t) (n / b + '0'));
				n %= b;
				b /= 10;
			}
		}
	}
}
