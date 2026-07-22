#include "test.h"

Test(print_percent, basic)
{
	cr_redirect_stdout();
	cr_assert_eq(print_percent(), 1);
	cr_assert_stdout_eq_str("%");
}