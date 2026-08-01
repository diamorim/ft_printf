#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int check_format(const char *format, int i, va_list args)
{
	int counter;
	counter = 0;
	if (format[i + 1] == 'c')
		counter = ft_printchar(va_arg(args, int));
	if (format[i + 1] == 's')
		counter = ft_printstr(va_arg(args, char *));
	// if (format[i + 1] == 'p')
	// 	counter = ft_printstr(va_arg(args, char *));
	if (format[i + 1] == 'd')
	counter = ft_printdecnumber(va_arg(args, double));
    if (format[i + 1] == 'i' || format[i + 1] == 'i')
		counter = ft_putnbr(va_arg(args, int));
	if (format[i + 1] == 'u')
		counter = ft_printunsignednum(va_arg(args, unsigned int));
	if (format[i + 1] == 'x')
		counter = ft_printhex(va_arg(args, unsigned int));
	if (format[i + 1] == 'X')
		counter = ft_print_caphex(va_arg(args, unsigned int));
	if (format[i + 1] == '%')
		counter = print_percent();
	return (counter);
}

int ft_printf(const char *format, ...)
{
    int i;
	int count;
    va_list args;
    va_start(args, format);

    i = 0;
	count = 0;
    while (format[i])
    {
		if(format[i] == '%')
		{
			count += check_format(format, i, args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
        i++;
    }
	va_end(args);
    return count;
}
