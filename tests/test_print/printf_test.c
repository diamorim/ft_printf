#include "../../ft_printf.h"
#include "stdio.h"

int main()
{
	char str[] = "hello";
	char *l = str;
	int i = 1748323;
	// unsigned long x = 5000000000;
	// ft_printf("%u\n", -1);
	// printf("%u\n", -1);
	// ft_printf("%u\n", 4294967295);
	// //printf("%u\n", 4294967295);
	// ft_printf("%u\n", 4294967297);
	// ft_printf("%u\n", x);
	//printf("%u\n", 4294967297);
	printf("%p\n", l);
	printf("%x", i);

	
	return 0;
}
