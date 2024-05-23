#include "../ft_printf.h"
#include "../libft/libft.h"

void test_printf(void);

int main(void)
{
	ft_printf("Hello %-15d, the answer is %s.\n", 42, "You");
	test_printf();

	return (0);
}
