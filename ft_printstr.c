#include "ft_printf.h"
#include "libft/libft.h"

int ft_printstr(char *str)
{
	if (str == NULL)
		return 0;
	
	write(1, str, ft_strlen(str));
	return ft_strlen(str);
}