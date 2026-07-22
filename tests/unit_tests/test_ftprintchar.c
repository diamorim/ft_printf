#include "test.h"

void repeat_putchar(char *str)
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		ft_printchar(str[i]);
	}
}

Test(ft_printchar, numbers)
{
	cr_redirect_stdout();
	repeat_putchar("09");
	cr_assert_stdout_eq_str("09");
}

Test(ft_printchar, letters)
{
	cr_redirect_stdout();
	repeat_putchar("azAZ");
	cr_assert_stdout_eq_str("azAZ");
}

Test(ft_printchar, special_characters)
{
	cr_redirect_stdout();
	repeat_putchar("+- #/\n");
	cr_assert_stdout_eq_str("+- #/\n");
}

Test(ft_printchar, empty_string)
{
	cr_redirect_stdout();
	repeat_putchar("");
	cr_assert_stdout_eq_str("");
}