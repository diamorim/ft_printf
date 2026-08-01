#include "ft_printf.h"

static long ft_trunc(double n)
{
    return (long)n;
}

static double ft_fmod(double value, double divisor)
{
    return value - ft_trunc(value / divisor) * divisor;
}

int	ft_printdecnumber(double n)
{
	int b;
	char *str1;
	char *str2;
	char *decnum;
	int count;
	b = n;
	n -= b;
	str1 = ft_itoa(b);
	ft_strlcat(str1, ".", ft_strlen(str1) + 2);
	while (ft_fmod(n, 1.0) != 0)
		n *= 10;
	str2 = ft_itoa(n);
	decnum = ft_strjoin(str1, str2);
	count = ft_strlen(decnum);
	write(1, decnum, count);
	return count;
}