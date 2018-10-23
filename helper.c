#include "./helper.h"

void print_character(const char c)
{
	write(1, &c, 1);
}

void print_string(const char s[])
{
	for (size_t i = 0; s[i]; ++i)
	{
		print_character(s[i]);
	}
}

void print_integer(int n)
{
	int b = 0;

	if (n == -2147483648)
	{
		print_string("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			print_character('-');
			n *= (int)-1;
		}
		if (n < 10)
		{
			print_character((char) (n + 48));
		}
		else
		{
			b = 1;
			while (b <= (n / 10))
			{
				b *= 10;
			}
			while (b >= 1)
			{
				print_character((char) (n / b + '0'));
				n %= b;
				b /= 10;
			}
		}
	}
}
