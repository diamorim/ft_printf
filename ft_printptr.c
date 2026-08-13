/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:22:50 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 10:31:35 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_ptr_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
	count++;
	return (count);
}

int	ft_printptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_print_ptr_hex(addr);
	return (count);
}
