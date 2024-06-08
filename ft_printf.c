/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:28:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/10 20:28:29 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>


int is_specifier(char c)
{
	char	*specs = "cspdiuxX";
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c == specs[i++])
			return (1);
	}
	return (0);
}

int is_flag(char c)
{
	return ((c == '-') | (c == '0') | (c == '#')
			| (c == ' ') | (c == '+'));
}


void analyse_mod(t_mod *mod, char *modifier)
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

void init_mod(t_mod *mod)
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

void restore_mod(t_mod *mod)
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
	// get char count of modifier
	while (!is_specifier(start[n]))
	{
		n++;
	}
	// printf("\nchars in modifier: %d\n", mod_len);
	modifier = ft_calloc(n + 1, sizeof (char));
	ft_memcpy(modifier, start + 1, n);
	// printf("modifier: %s\n", modifier);
	// analyse modifier
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
				// print_mod(mod);
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


#include <limits.h>
// #include ".tests/test_d.c"
// // #include ".tests/test_p.c"
// #include ".tests/test_x.c"

int main(void)
{
	// // test the behaviour with NULL
	// c1 = printf(" >>%.03p<<>>%.3p<<>>%3.1p<<>>%9.1p<<>>%-3.1p<<\n", NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%.03p<<>>%.3p<<>>%3.1p<<>>%9.1p<<>>%-3.1p<<\n", NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);

	// c1 = printf(" >>%23p<<>>%.p<<>>%32p<<>>%5p<<>>%6p<<\n", NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%23p<<>>%.p<<>>%32p<<>>%5p<<>>%6p<<\n", NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);

	// c1 = printf(" >>%.09p<<>>%.9p<<>>%3.6p<<>>%20.6p<<>>%-3.8p<<>>%-10.8p<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%.09p<<>>%.9p<<>>%3.6p<<>>%20.6p<<>>%-3.8p<<>>%-10.8p<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);

	// ft_printf(">>%5%");
	// ft_printf(">>%-5%");
	// ft_printf(">>%05%");
	// ft_printf(">>%-05%");
	// ft_printf(">>%010%");
	// ft_printf(">>percent 1 %012%");
	// ft_printf(">>percent 2 %12%");
	// ft_printf(">>percent 3 %-12%");
	// ft_printf(">>percent 4 %0%");
	// ft_printf(">>%-192.131%");
	// ft_printf(">>%-70.193x%-140c%168c%026.51%%0125.119X" ,1102840003u,-50,-17,3721437512u);
	// ft_printf(">>%10c%0036.99%" ,9);
	// ft_printf(">>%-50c%-85.157%%--58.188X" ,9,274691972u);
	// ft_printf(">>%-132.186x%00129.46%%-191.181X%-75.123d%0033.123u" ,2222238685u,3146675666u,251185067,3453417465u);
	// ft_printf(">>%--198.101X%0145.12%%172c" ,935976394u,-118);
	// ft_printf(">>%52c%00040.166%%-131c%-12.99s" ,-57,123,"k\r/ULCoKi0");
	// ft_printf(">>%-175.96%%-153.x" ,822360617u);
	// ft_printf(">>%-166.180X%--18.47d%---111.87%%8p%0114.24X" ,1637127682u,-1931431309,(void*)3522468094256045905lu,4291674618u);
	// ft_printf(">>%-55.46%%--171.99s%--56.41X%-173X" ,"7",3917830995u,3557113666u);
	// ft_printf(">>%--85.97%%---129c" ,33);
	// ft_printf(">>%-58.131%");

	// // test the behaviour with NULL
	// c1 = printf(" >>%.03s<<>>%.3s<<>>%3.1s<<>>%9.1s<<>>%-3.1s<<\n", NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%.03s<<>>%.3s<<>>%3.1s<<>>%9.1s<<>>%-3.1s<<\n", NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);


	// c1 = printf(" >>%23s<<>>%.s<<>>%32s<<>>%5s<<>>%6s<<\n", NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%23s<<>>%.s<<>>%32s<<>>%5s<<>>%6s<<\n", NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);

	// c1 = printf(" >>%.09s<<>>%.9s<<>>%3.6s<<>>%20.6s<<>>%-3.8s<<>>%-10.8s<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	// c2 = ft_printf("*>>%.09s<<>>%.9s<<>>%3.6s<<>>%20.6s<<>>%-3.8s<<>>%-10.8s<<\n", NULL, NULL, NULL, NULL, NULL, NULL);
	// printf("\t%d|%d\n", c1, c2);


	// char *str = NULL;
	// int res = write(1, str, sizeof(str));
	// printf("%d", res);

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

