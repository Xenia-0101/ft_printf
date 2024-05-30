#include "../ft_printf.h"
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>

void test_printf(void);

int main(void)
{
	// ft_printf("Hello %-15d, the answer is %s.\n", 42, "You");
	// test_printf();

	// int c = -55;
	// int val = 4095;

	// int oone = ft_printf("unsigned int: %u\n", c);
	// int ttwo = ft_printf("unsigned int: %d\n", c);
	// int tthree = ft_printf("%u\n", UINT_MAX);

	// int one = printf("unsigned int: %u\n", c);
	// int two = printf("unsigned int: %d\n", c);
	// int three = printf("%u\n", UINT_MAX);

	// printf("%d\t%d\t%d\n%d\t%d\t%d\n", oone, ttwo, tthree, one, two, three);

/* 	char ptr = 10;
	char *add = &ptr;

	// uint64_t x = (uint64_t) &ptr;
	printf("%x\n", add);
	printf("%p\n", add); */

	int random = 55;

	int res2 = ft_printf("%#.5x\t", random);
	int res1 = printf("%x\n", random);
	int res3 = printf(">%-#15x<\n", random);
	printf(">%#15x<\n", random);

	printf("%d\t%d\n", res2, res1);


	return (0);
}
