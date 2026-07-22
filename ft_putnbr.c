#include "printf.h"
#include "libft/libft.h"
#include <unistd.h>

int	ft_putnbr(int n)
{
	int	num_amm;

	num_amm = ft_strlen(ft_itoa(n));
	if(!n)
		return 0;
	write(1, ft_itoa(n), ft_strlen(ft_itoa(n)));

	return num_amm; 
}


