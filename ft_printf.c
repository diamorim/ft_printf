/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 06:25:08 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 15:14:00 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	check_format(const char *format, int i, va_list args)
{
	int	counter;

	counter = 0;
	if (format[i + 1] == 'c')
		counter = ft_printchar(va_arg(args, int));
	else if (format[i + 1] == 's')
		counter = ft_printstr(va_arg(args, char *));
	else if (format[i + 1] == 'p')
		counter = ft_printptr(va_arg(args, void *));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		counter = ft_putnbr(va_arg(args, int));
	else if (format[i + 1] == 'u')
		counter = ft_printunsignednum(va_arg(args, unsigned int));
	else if (format[i + 1] == 'x')
		counter = ft_printhex(va_arg(args, unsigned int));
	else if (format[i + 1] == 'X')
		counter = ft_print_caphex(va_arg(args, unsigned int));
	else if (format[i + 1] == '%')
		counter = print_percent();
	else
	{
		print_percent();
		counter = ft_printchar(va_arg(args, int));
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
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
	return (count);
}
