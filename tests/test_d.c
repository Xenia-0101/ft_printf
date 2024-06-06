/* int main(void)
{
	//	Testing d
	int num1 = 789;
	int num2 = -123;

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
	return (0);
}
 */
