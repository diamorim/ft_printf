/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:29:04 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 10:41:28 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr(int n)
{
	int		num_amm;
	char	*val;

	val = ft_itoa(n);
	num_amm = ft_strlen(val);
	write(1, val, ft_strlen(val));
	free(val);
	return (num_amm);
}
