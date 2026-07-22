#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int ft_printstr(char *str);
int ft_printchar(int c);
int print_percent();
int ft_printunsignednum(unsigned int n);

#endif