/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:20:32 by damorim-          #+#    #+#             */
/*   Updated: 2026/08/13 10:21:59 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_printstr(char *str);
int	ft_printchar(int c);
int	print_percent(void);
int	ft_printunsignednum(unsigned int n);
int	ft_printhex(unsigned int n);
int	ft_print_caphex(unsigned int n);
int	ft_printptr(void *ptr);

#endif