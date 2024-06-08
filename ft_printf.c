/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:28:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:40:25 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>


static int is_specifier(char c)
{
	char	*specs = "cspdiuxX%";
	int		i;

	i = 0;
	while (i < 9)
	{
		if (c == specs[i++])
			return (1);
	}
	return (0);
}

static int is_flag(char c)
{
	return ((c == '-') | (c == '0') | (c == '#')
			| (c == ' ') | (c == '+'));
}


static void analyse_mod(t_mod *mod, char *modifier)
{
	int n;

	n = 0;
	while (is_flag(modifier[n]))
	{
		if (modifier[n] == '0')
		{
			mod->flag.zero = 1;
		}
		else if (modifier[n] == '-')
		{
			mod->flag.dash = 1;
			mod->flag.zero = 0;
		}
		else if (modifier[n] == ' ')
		{
			mod->flag.spac = 1;
		}
		else if (modifier[n] == '+')
		{
			mod->flag.plus = 1;
		}
		else if (modifier[n] == '#')
		{
			mod->flag.hash = 1;
		}
		n++;
	}
	if (ft_isdigit(modifier[n]))
	{
		(mod->widt.exists) = 1;
		(mod->widt.value) = ft_atoi(&modifier[n]);
		while (ft_isdigit(modifier[n]))
		{
			n++;
		}
	}
	if (modifier[n] == '.')
	{
		(mod->prec.exists) = 1;
		n++;
		(mod->prec.value) = ft_atoi(&modifier[n]);
		while (ft_isdigit(modifier[n]))
		{
			n++;
		}
		mod->flag.zero = 0;
	}
	if (!is_specifier(modifier[n]))
		return;							// what happens if no spec ??
	else
	{
		(mod->spec.exists) = 1;
		(mod->spec.value) = modifier[n];
	}
}

static void init_mod(t_mod *mod)
{
	mod->total = 0;

	mod->flag.dash = 0;
	mod->flag.zero = 0;
	mod->flag.spac = 0;
	mod->flag.plus = 0;
	mod->flag.hash = 0;

	mod->widt.exists = 0;
	mod->widt.value = 0;

	mod->prec.exists = 0;
	mod->prec.value = 0;

	mod->spec.exists = 0;
	mod->spec.value = 0;
}

static void restore_mod(t_mod *mod)
{
	mod->flag.dash = 0;
	mod->flag.zero = 0;
	mod->flag.spac = 0;
	mod->flag.plus = 0;
	mod->flag.hash = 0;

	mod->widt.exists = 0;
	mod->widt.value = 0;

	mod->prec.exists = 0;
	mod->prec.value = 0;

	mod->spec.exists = 0;
	mod->spec.value = 0;
}

void print_mod(t_mod *mod)
{
	if (mod->flag.zero)
		printf("mod->flag.zero: %d\n", mod->flag.zero);
	if (mod->flag.dash)
		printf("mod->flag.dash: %d\n", mod->flag.dash);
	if (mod->flag.spac)
		printf("mod->flag.spac: %d\n", mod->flag.spac);
	if (mod->flag.zero)
		printf("mod->flag.plus: %d\n", mod->flag.plus);
	if (mod->flag.hash)
		printf("mod->flag.hash: %d\n", mod->flag.hash);
	if (mod->widt.exists)
		printf("mod->widt.value: %d\n", mod->widt.value);
	if (mod->prec.exists)
		printf("mod->prec.value: %d\n", mod->prec.value);
	if (mod->spec.exists)
		printf("mod->spec.value: %c\n", mod->spec.value);
}

int record_modifier(t_mod *mod, const char *string)
{
	int n;
	char *start;
	char *modifier;

	n = 0;
	start = ft_strchr(string, '%');
	n++;
	while (!is_specifier(start[n]))
	{
		n++;
	}
	modifier = ft_calloc(n + 1, sizeof (char));
	ft_memcpy(modifier, start + 1, n);
	analyse_mod(mod, modifier);
	free(modifier);
	return (n);
}

int ft_printf(const char *string, ...)
{
	int n;
	size_t res;
	va_list vars;
	t_mod *mod;

	mod = malloc(sizeof (t_mod));
	if (!mod)
		return (0);

	init_mod(mod);

	va_start(vars, string);

	n = 0;
	while (string[n])
	{
		if (string[n] == '%')
		{
			if (string[n + 1] == '%')
			{
				write(1, &string[n], 1);
				mod->total++;
				n += 2;
			}
			else
			{
				n += record_modifier(mod, (string + n)) + 1;
				decide_format(mod, &vars);
				restore_mod(mod);
			}
		}
		else
		{
			mod->total += write(1, &string[n], 1);
			n++;
		}
	}
	va_end(vars);
	res = mod->total;
	free(mod);
	return (res);
}

/*
#include <limits.h>

int main(void)
{
	int c1, c2;
	int num1 = 789;
	int num2 = -123;

	printf("BASIC INPUT d\n");
	c1 = printf("  %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	c2 = ft_printf("* %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("\t%d|%d\n", c1, c2);

	printf("BASIC INPUT i\n");
	c1 = printf("  %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	c2 = ft_printf("* %d  %d  %d  %d  %d \n", num1, num2, INT_MAX, INT_MIN, 0);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT p\n");
	c1 = printf(" >> %p <<>> %p <<>> %p <<>> %p %p <<>> %p %p <<>> %p %p <<>> %p %p <<\n", -1, 1, 15, LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX, 0, 0);
	c2 = ft_printf("*>> %p <<>> %p <<>> %p <<>> %p %p <<>> %p %p <<>> %p %p <<>> %p %p <<\n", -1, 1, 15, LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX, 0, 0);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT c\n");
	c1 = printf(" >>%c<>%c<>%c<>%c<>%c<>%c<>%c<>%c %c %c<\n", '0', '0' - 256, '0' + 256, 0, '1', ' ', '2', 55, '\0', 23);
	c2 = printf("*>>%c<>%c<>%c<>%c<>%c<>%c<>%c<>%c %c %c<\n", '0', '0' - 256, '0' + 256, 0, '1', ' ', '2', 55, '\0', 23);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT s\n");
	c1 = printf(" >>%s<>%s<<>>%s %s %s<<>>%s\n","abc", "123", "", " ", "  ", NULL);
	c2 = ft_printf("*>>%s<>%s<<>>%s %s %s<<>>%s\n","abc", "123", "", " ", "  ", NULL);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT u\n");
	c1 = printf("<%u>>%u<<>>%u<<>>%u<<%u>>%u<<%u>>%u<<>>%u<<>>%u>%u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, UINT_MAX, 0, -42, 42, LLONG_MAX, LLONG_MIN);
	c2 = ft_printf("<%u>>%u<<>>%u<<>>%u<<%u>>%u<<%u>>%u<<>>%u<<>>%u>%u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, UINT_MAX, 0, -42, 42, LLONG_MAX, LLONG_MIN);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT x and X\n");
	c1 = printf("<%x>>%X<<>>%x<<>>%X<<%x>>%X<<%x>>%X<<>>%x<<>>%X>%x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, UINT_MAX, 0, -42, 42, LLONG_MAX, LLONG_MIN);
	c2 = ft_printf("<%x>>%X<<>>%x<<>>%X<<%x>>%X<<%x>>%X<<>>%x<<>>%X>%x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, UINT_MAX, 0, -42, 42, LLONG_MAX, LLONG_MIN);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nBASIC INPUT %%\n");
	c1 = printf("%% %% %%%% %%%%%% %%\n");
	c2 = ft_printf("%% %% %%%% %%%%%% %%\n");
	printf("\t%d|%d\n", c1, c2);


	printf("\n\n. d\n");
	c1 = printf(" > %.5d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <> %.0d <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	c2 = ft_printf(" > %.5d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <> %.0d <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" > %.15d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <> %.0d <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	c2 = ft_printf(" > %.15d <> %.5d <> %.5d <> %.5d <> %.d <> %.0d <> %.0d <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\n. i\n");
	c1 = printf(" > %.5i <> %.5i <> %.5i <> %.5i <> %.i <> %.0i <> %.0i <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	c2 = ft_printf(" > %.5i <> %.5i <> %.5i <> %.5i <> %.i <> %.0i <> %.0i <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" > %.15i <> %.5i <> %.5i <> %.5i <> %.i <> %.0i <> %.0i <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	c2 = ft_printf(" > %.15i <> %.5i <> %.5i <> %.5i <> %.i <> %.0i <> %.0i <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\n. u\n");
	c1 = printf(" > %.5u <> %.5u <> %.5u <> %.5u <> %.u <> %.0u <> %.0u <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	c2 = ft_printf(" > %.5u <> %.5u <> %.5u <> %.5u <> %.u <> %.0u <> %.0u <\n", 12, 123, 12345, 123456789, 123, 123, 0);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" > %.15u <> %.5u <> %.5u <> %.5u <> %.u <> %.0u <> %.0u <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	c2 = ft_printf(" > %.15u <> %.5u <> %.5u <> %.5u <> %.u <> %.0u <> %.0u <\n", INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42, LLONG_MAX);
	printf("\t%d|%d\n", c1, c2);


	printf("\n\n. x\n");
	c1 = printf(">>%.8x>>%.9X>>%.10x>>%.11x>>%.12X>>%.13X>>%.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(">>%.8x>>%.9X>>%.10x>>%.11x>>%.12X>>%.13X>>%.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);


	printf("\n\n. s\n");
	c1 = printf(" %.2s<>%.3s<>%.4s<>%.5s<>%.1s \n", " - ", "", "4", "", "2 ");
	c2 = ft_printf(" %.2s<>%.3s<>%.4s<>%.5s<>%.1s \n", " - ", "", "4", "", "2 ");
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(">%.0s>>%.s>>%.2s>>%.5s>>%.10s\n", "hello", "hello", "hello", "hello", "hello");
	c2 = ft_printf(">%.0s|>>%.s|>>%.2s>>%.5s>>%.10s\n", "hello", "hello", "hello", "hello", "hello");
	printf("\t%d|%d\n", c1, c2);

	printf("\n\n-\n");
	c1 = printf(" |<>%-9d|<> %-10d|<> %-11d|<> %-12d|<> %-13d|<> %-14d|<> %-15d|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(" |<>%-9d|<> %-10d|<> %-11d|<> %-12d|<> %-13d|<> %-14d|<> %-15d|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);
	c1 = printf(" |<>%-9i|<> %-10i|<> %-11i|<> %-12i|<> %-13i|<> %-14i|<> %-15i|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(" |<>%-9i|<> %-10i|<> %-11i|<> %-12i|<> %-13i|<> %-14i|<> %-15i|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);
	c1 = printf(" |<>%-9u|<> %-10u|<> %-11u|<> %-12u|<> %-13u|<> %-14u|<> %-15u|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(" |<>%-9u|<> %-10u|<> %-11u|<> %-12u|<> %-13u|<> %-14u|<> %-15u|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);
	c1 = printf(" |<>%-9x|<> %-10x|<> %-11x|<> %-12x|<> %-13x|<> %-14x|<> %-15x|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(" |<>%-9x|<> %-10x|<> %-11x|<> %-12x|<> %-13x|<> %-14x|<> %-15x|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);
	c1 = printf(" |<>%-9X|<> %-10X|<> %-11X|<> %-12X|<> %-13X|<> %-14X|<> %-15X|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	c2 = ft_printf(" |<>%-9X|<> %-10X|<> %-11X|<> %-12X|<> %-13X|<> %-14X|<> %-15X|<>\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\t%d|%d\n", c1, c2);


	printf("\n\nTEST %%\n");
	c1 = printf(" >>%5%<<>>%-5%<<>>%05%<<>>%010%<<%% %%%% %%%%% %\n");
	c2 = ft_printf("*>>%5%<<>>%-5%<<>>%05%<<>>%010%<<%% %%%% %%%%% %\n");
	printf("\t%d|%d\n", c1, c2);

	// test the behaviour with NULL
	printf("\n\nTEST NULL with s\n");
	c1 = printf(" >>%.03s<<>>%.3s<<>>%3.1s<<>>%9.1s<<>>%-3.1s<<\n", NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%.03s<<>>%.3s<<>>%3.1s<<>>%9.1s<<>>%-3.1s<<\n", NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" >>%23s<<>>%.s<<>>%32s<<>>%5s<<>>%6s<<\n", NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%23s<<>>%.s<<>>%32s<<>>%5s<<>>%6s<<\n", NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" >>%.09s<<>>%.9s<<>>%3.6s<<>>%20.6s<<>>%-3.8s<<>>%-10.8s<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%.09s<<>>%.9s<<>>%3.6s<<>>%20.6s<<>>%-3.8s<<>>%-10.8s<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);

	printf("\n\nTEST NULL with p\n");
	c1 = printf(" >>%.03p<<>>%.3p<<>>%3.1p<<>>%9.1p<<>>%-3.1p<<\n", NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%.03p<<>>%.3p<<>>%3.1p<<>>%9.1p<<>>%-3.1p<<\n", NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" >>%23p<<>>%.p<<>>%32p<<>>%5p<<>>%6p<<\n", NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%23p<<>>%.p<<>>%32p<<>>%5p<<>>%6p<<\n", NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);

	c1 = printf(" >>%.09p<<>>%.9p<<>>%3.6p<<>>%20.6p<<>>%-3.8p<<>>%-10.8p<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("*>>%.09p<<>>%.9p<<>>%3.6p<<>>%20.6p<<>>%-3.8p<<>>%-10.8p<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	printf("\t%d|%d\n", c1, c2);



	// // test zero precision
	// c1 = printf(" >>%d<<>>%10d<<>>%10.5d<<>>%10.0d<<>>%10.d<<>>%.0d<<\n", 12, 12, 12, 12, 12, 12);
	// c2 = ft_printf("*>>%d<<>>%10d<<>>%10.5d<<>>%10.0d<<>>%10.d<<>>%.0d<<\n", 12, 12, 12, 12, 12, 12);
	// printf("\t%d|%d\n", c1, c2);
	// c1 = printf(" >>%d<<>>%10d<<>>%10.5d<<>>%10.0d<<>>%10.d<<\n", 0, 0, 0, 0, 0, 0);
	// c2 = ft_printf("*>>%d<<>>%10d<<>>%10.5d<<>>%10.0d<<>>%10.d<<\n", 0, 0, 0, 0, 0, 0);
	// printf("\t%d|%d\n", c1, c2);
	// c1 = printf(" >>%i<<>>%10i<<>>%10.5i<<>>%10.0i<<>>%10.i<<>>%.0i<<\n", 12, 12, 12, 12, 12, 12);
	// c2 = ft_printf("*>>%i<<>>%10i<<>>%10.5i<<>>%10.0i<<>>%10.i<<>>%.0i<<\n", 12, 12, 12, 12, 12, 12);
	// printf("\t%i|%i\n", c1, c2);
	// c1 = printf(" >>%i<<>>%10i<<>>%10.5i<<>>%10.0i<<>>%10.i<<\n", 0, 0, 0, 0, 0, 0);
	// c2 = ft_printf("*>>%i<<>>%10i<<>>%10.5i<<>>%10.0i<<>>%10.i<<\n", 0, 0, 0, 0, 0, 0);
	// printf("\t%d|%d\n", c1, c2);
	// c1 = printf(" >>%u<<>>%10u<<>>%10.5u<<>>%10.0u<<>>%10.u<<>>%.0u<<\n", 12, 12, 12, 12, 12, 12);
	// c2 = ft_printf("*>>%u<<>>%10u<<>>%10.5u<<>>%10.0u<<>>%10.u<<>>%.0u<<\n", 12, 12, 12, 12, 12, 12);
	// printf("\t%d|%d\n", c1, c2);
	// c1 = printf(" >>%u<<>>%10u<<>>%10.5u<<>>%10.0u<<>>%10.u<<\n", 0, 0, 0, 0, 0, 0);
	// c2 = ft_printf("*>>%u<<>>%10u<<>>%10.5u<<>>%10.0u<<>>%10.u<<\n", 0, 0, 0, 0, 0, 0);
	// printf("\t%d|%d\n", c1, c2);

	// test_d();
}
// gcc *.c ./libft/libft.a && ./a.out
 */

