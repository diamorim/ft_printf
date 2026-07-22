#include "test.h"

Test(printnbr, basic)
{
	cr_redirect_stdout();
	cr_assert_eq(ft_putnbr(2147483647), 10);
	cr_assert_eq(ft_putnbr(-2147483648), 11);
	cr_assert("2147483647-2147483648");
}