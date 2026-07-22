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
	int	len;

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
int ft_printunsignednum(unsigned int n)
{
	int counter;

	
	write(1, ft_unsigned_itoa(n), ft_strlen(ft_unsigned_itoa(n)));
	counter = ft_strlen(ft_unsigned_itoa(n));
	return counter;
}