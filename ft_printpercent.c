#include "ft_printf.h"

int print_percent()
{
	write(1, &"%", 1);
	return 1;
}