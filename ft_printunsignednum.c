/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignednum.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:28:06 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 15:14:20 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*str;
	int				len;

	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	if (!str)
		return (NULL);
	while (n >= 10)
	{
		str[--len] = '0' + n % 10;
		n /= 10;
	}
	str[len - 1] = '0' + (n % 10);
	return (str);
}

int	ft_printunsignednum(unsigned int n)
{
	int		counter;
	char	*str;

	str = ft_unsigned_itoa(n);
	write(1, str, ft_strlen(str));
	counter = ft_strlen(str);
	free(str);
	return (counter);
}
