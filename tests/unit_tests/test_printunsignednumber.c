#include "test.h"

Test(printunsignednum, basic)
{
	cr_redirect_stdout();
	cr_assert_eq(ft_printunsignednum(123), 3);
	cr_assert_stdout_eq_str("123");
}
Test(printunsignednum, big_numbers)
{
	cr_redirect_stdout();
	cr_assert_eq(ft_printunsignednum(4294967293), 10, "%d");
	cr_assert_stdout_eq_str("4294967293", "%d");
}