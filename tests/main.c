#include "../ft_printf.h"
#include "../libft/libft.h"

int main(void)
{
	ft_printf("Hello %-15d, the answer is %s.\n", 42, "You");

	printf("\n");

	char greet[] = "Hey >:-)";
	ft_printf("|------------|-----------------|\n");
	ft_printf("| %-10s | %-15s |\n", "Input", "char[] Hey >:-)");
	ft_printf("|............|.................|\n");
	ft_printf("| %-10s | %15s |\n", "Format", "Print");
	ft_printf("|------------|-----------------|\n");
	ft_printf("| %-10s | %s |\n", "%s", greet);
	ft_printf("| %-10s | %5s |\n", "%5s", greet);
	ft_printf("| %-10s | %5.2s |\n", "%5.2s", greet);
	ft_printf("| %-10s | %8s |\n", "%8s", greet);
	ft_printf("| %-10s | %15s |\n", "%15s", greet);
	ft_printf("| %-10s | %-15s |\n", "%-15s", greet);
	ft_printf("|------------|-----------------|\n");

	printf("\n");

	printf("|------------|-----------------|\n");
	printf("| %-10s | %-15s |\n", "Input", "char[] Hey >:-)");
	printf("|............|.................|\n");
	printf("| %-10s | %15s |\n", "Format", "Print");
	printf("|------------|-----------------|\n");
	printf("| %-10s | %s |\n", "%s", greet);
	printf("| %-10s | %5s |\n", "%5s", greet);
	printf("| %-10s | %5.2s |\n", "%5.2s", greet);
	printf("| %-10s | %8s |\n", "%8s", greet);
	printf("| %-10s | %15s |\n", "%15s", greet);
	printf("| %-10s | %-15s |\n", "%-15s", greet);
	printf("|------------|-----------------|\n");

	printf("\n");

	char c_1 = 'r';
	char *c_2 = "hell";
	int c_3 = 97;
	int c_4 = 255;

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-46s |\n", "Testing %c specifier.");
	ft_printf("|............|.................|.................|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "char c = r", c_1);
	ft_printf("| %-9s | %15s | %14c |\n", "%15c", "&(char *c = hell)", *c_2);
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 97", c_3);
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 255", c_4);
	ft_printf("|------------|-----------------|-----------------|\n");

	printf("\n");

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-46s |\n", "Testing %c specifier.");
	printf("|............|.................|.................|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15c |\n", "%15c", "char c = r", c_1);
	printf("| %-9s | %15s | %14c |\n", "%15c", "&(char *c = hell)", *c_2);
	printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 97", c_3);
	printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 255", c_4);
	printf("|------------|-----------------|-----------------|\n");

	printf("\n");

	int val = 4095;
	int hex_val = 0xfff;

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15d | %15d |\n", "%d", val, hex_val);
	ft_printf("| %-10s | %-15d | %-15d |\n", "%-d", val, hex_val);
	ft_printf("| %-10s | %015d | %015d |\n", "%0d", val, hex_val);
	ft_printf("| %-10s | %15.d | %15.d |\n", "%.d", val, hex_val);
	ft_printf("| %-10s | %15.4d | %15.4d |\n", "%.4d", val, hex_val);
	ft_printf("| %-10s | %15.8d | %15.8d |\n", "%.8d", val, hex_val);
	ft_printf("| %-10s | %-15.8d | %-15.8d |\n", "%-.8d", val, hex_val);
	ft_printf("|------------|-----------------|-----------------|\n");

	printf("\n");

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15d | %15d |\n", "%d", val, hex_val);
	printf("| %-10s | %-15d | %-15d |\n", "%-d", val, hex_val);
	printf("| %-10s | %015d | %015d |\n", "%0d", val, hex_val);
	printf("| %-10s | %15.d | %15.d |\n", "%.d", val, hex_val);
	printf("| %-10s | %15.4d | %15.4d |\n", "%.4d", val, hex_val);
	printf("| %-10s | %15.8d | %15.8d |\n", "%.8d", val, hex_val);
	printf("| %-10s | %-15.8d | %-15.8d |\n", "%-.8d", val, hex_val);
	printf("|------------|-----------------|-----------------|\n");

	return (0);
}
