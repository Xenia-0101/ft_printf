#include <limits.h>

void test_x(void)
{
	int u, pf, fp;

	u = 0xFFFFFFFF;

	pf = printf("printf : %#20.15Xq%#xr\n", u, u);
	fp = ft_printf("ftprint: %#20.15Xq%#xr\n", u, u);
	printf ("pf = %d, fp = %d\n", pf, fp);

	pf = printf(" qq%#xq q%#xq q%#xq q%#xq q%#xq q%#xq q%#xq\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	fp = ft_printf(" qq%#xq q%#xq q%#xq q%#xq q%#xq q%#xq q%#xq\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf ("pf = %d, fp = %d\n", pf, fp);

	pf = printf(" qq%#xq \n", 0);
	fp = ft_printf(" qq%#xq \n", 0);
	printf ("pf = %d, fp = %d\n", pf, fp);
}
