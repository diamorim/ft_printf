#include "test.h"

Test(ft_printstr, basic)
{
	cr_redirect_stdout();
	ft_printstr("a z 0 9 A Z");
	cr_assert_stdout_eq_str("a z 0 9 A Z");
}
Test(ft_printstr, special_characters)
{
	cr_redirect_stdout();
	ft_printstr(" \n \\ =+_-&&*$%d");
	cr_assert_stdout_eq_str(" \n \\ =+_-&&*$%d");
}

Test(ft_printstr, return_value)
{
	cr_assert_eq(ft_printstr("hello\n"), 6);
}

Test(ft_printstr, null_guard)
{
	cr_expect_not(ft_printstr(NULL));
}