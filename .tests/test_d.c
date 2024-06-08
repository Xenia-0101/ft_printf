

void test_d(void)
{
	//	Testing d
	int num1 = 789;
	int num2 = -123;
	int c1, c2;

	printf(" >>% 010d<<>>% 05d<<\n", 123, 123456);
	ft_printf("*>>% 010d<<>>% 05d<<\n\n", 123, 123456);
	printf(" >>%010d<<>>%05d<<\n", 123, 123456);
	ft_printf("*>>%010d<<>>%05d<<\n\n", 123, 123456);

	printf(" >>% 010d<<>>% 05d<<\n", -123, -123456);
	ft_printf("*>>% 010d<<>>% 05d<<\n\n", -123, -123456);

	printf(" >>%010d<<>>%05d<<\n", -123, -123456);
	ft_printf("*>>%010d<<>>%05d<<\n\n", -123, -123456);

	printf(" >>% -10d<<>>% -5d<<\n", 123, 123456);
	ft_printf("*>>% -10d<<>>% -5d<<\n\n", 123, 123456);
	printf(" >>%-10d<<>>%-5d<<\n", 123, 123456);
	ft_printf("*>>%-10d<<>>%-5d<<\n\n", 123, 123456);
	printf(" >>% -10d<<>>% -5d<<\n", -123, -123456);
	ft_printf("*>>% -10d<<>>% -5d<<\n\n", -123, -123456);
	printf(" >>%-10d<<>>%-5d<<\n", -123, -123456);
	ft_printf("*>>%-10d<<>>%-5d<<\n\n", -123, -123456);

	printf(" >>%+-10d<<>>%+-5d<<\n", 123, 123456);
	ft_printf("*>>%+-10d<<>>%+-5d<<\n\n", 123, 123456);
	printf(" >>%-10d<<>>%-5d<<\n", 123, 123456);
	ft_printf("*>>%-10d<<>>%-5d<<\n\n", 123, 123456);
	printf(" >>%+-10d<<>>%+-5d<<\n", -123, -123456);
	ft_printf("*>>%+-10d<<>>%+-5d<<\n\n", -123, -123456);
	printf(" >>%-10d<<>>%-5d<<\n", -123, -123456);
	ft_printf("*>>%-10d<<>>%-5d<<\n\n", -123, -123456);

	//		basic input
	printf("basic input\n");
	printf("  %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %d  %d  %d  %d  %d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		flag 0
	printf("flag 0\n");
	printf("  %010d  %010d  %010d  %010d  %010d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %010d  %010d  %010d  %010d  %010d \n\n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  %0d  %0d  %0d  %0d  %0d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %0d  %0d  %0d  %0d  %0d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		flag -
	printf("flag -\n");
	printf("  %-10d  %-10d  %-10d  %-10d  %-10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %-10d  %-10d  %-10d  %-10d  %-10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  %-d  %-d  %-d  %-d  %-d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %-d  %-d  %-d  %-d  %-d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		flag ' '
	printf("flag space\n");
	printf("  %10d  %10d  %10d  %10d  %10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %10d  %10d  %10d  %10d  %10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  % 10d  % 10d  % 10d  % 10d  % 10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* % 10d  % 10d  % 10d  % 10d  % 10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  % d  % d  % d  % d  % d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* % d  % d  % d  % d  % d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		flag +
	printf("flag +\n");
	printf("  %+10d  %+10d  %+10d  %+10d  %+10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %+10d  %+10d  %+10d  %+10d  %+10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  %+d  %+d  %+d  %+d  %+d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %+d  %+d  %+d  %+d  %+d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		flag #
	printf("flag #\n");
	printf("  %#10d  %#10d  %#10d  %#10d  %#10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %#10d  %#10d  %#10d  %#10d  %#10d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("  %#d  %#d  %#d  %#d  %#d \n", num1, num2, INT_MAX, INT_MIN, 0);
	ft_printf("* %#d  %#d  %#d  %#d  %#d \n\n", num1, num2, INT_MAX, INT_MIN, 0);

	//		precision
	printf("precision\n");
	printf(" > %.5d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <\n", 12, 123, 12345, 123456789, 123, 123);
	ft_printf("*> %.5d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <\n\n", 12, 123, 12345, 123456789, 123, 123);

	//		combinations - ignore 0 if -
	printf("combine - and 0\n");
	printf(" > %-05d <> %0-5d <\n", num1, num1);
	ft_printf("*> %-05d <> %0-5d <\n\n", num1, num1);

	//		test precision with negative numbers
	c1 = printf("> %.2d <\n", -1);
	c2 = ft_printf("> %.2d <\n", -1);
	printf("%d\t%d\n", c1, c2);
	c1 = printf("> %.3d <\n", -11);
	c2 = ft_printf("> %.3d <\n", -11);
	printf("%d\t%d\n", c1, c2);

	// if precision is given, 0 is ignored
	printf("%08.3d\n", 8375);
	ft_printf("%08.3d\n", 8375);

	// if prec is 0 or none and num is zero, nothing is printed

	printf(">>%5.d<<\n", 0);
	ft_printf("*>%5.d<<\n", 0);
	printf(">>%-5.0d<<\n", 0);
	ft_printf("*>%-5.0d<<\n", 0);
	printf(">>%-5.d<<\n", 0);
	ft_printf("*>%-5.d<<\n", 0);
}

