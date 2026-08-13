/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:29:55 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 10:30:54 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_printhex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
	count++;
	return (count);
}

int	ft_print_caphex(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_caphex(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
	count++;
	return (count);
}
