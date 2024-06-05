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
	return ((c == '-') | (c == '0') | (c == '#'));
}

void analyse_mod(t_mod *mod, char *modifier)
{
	int n;

	n = 0;
	if (is_flag(modifier[n]))
	{
		(mod->flag.exists) = 1;
		(mod->flag.value) = modifier[n];
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

	mod->flag.exists = 0;
	mod->flag.value = 0;

	mod->widt.exists = 0;
	mod->widt.value = 0;

	mod->prec.exists = 0;
	mod->prec.value = 0;

	mod->spec.exists = 0;
	mod->spec.value = 0;
}

void restore_mod(t_mod *mod)
{
	mod->flag.exists = 0;
	mod->flag.value = 0;

	mod->widt.exists = 0;
	mod->widt.value = 0;

	mod->prec.exists = 0;
	mod->prec.value = 0;

	mod->spec.exists = 0;
	mod->spec.value = 0;
}

void print_mod(t_mod *mod)
{
	if (mod->flag.exists)
	{
		printf("mod->flag.value: %c\n", mod->flag.value);
	}
	if (mod->widt.exists)
	{
		printf("mod->widt.value: %d\n", mod->widt.value);
	}
	if (mod->prec.exists)
	{
		printf("mod->prec.value: %d\n", mod->prec.value);
	}
	if (mod->spec.exists)
	{
		printf("mod->spec.value: %c\n", mod->spec.value);
	}
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
			write(1, &string[n], 1);
			mod->total++;
			n++;
		}
	}
	va_end(vars);
	res = mod->total;
	free(mod);
	return (res);
}


#include <limits.h>
int main(void)
{
	// int res1 = printf(">> %-2u <<\n", -1);
	// int res11 = ft_printf(">> %-2u <<\n", -1);
	// int res2 = printf(">> %-13u <<\n", UINT_MAX);
	// int res22 = ft_printf(">> %-13u <<\n", UINT_MAX);
	// int res3 = printf(">> %-1x <<\n", 0);
	// int res33 = ft_printf(">> %-1x <<\n", 0);

	// printf("%d\t%d\t%d\n%d\t%d\t%d\n", res1, res2, res3, res11, res22, res33);

	// int rres1 = printf(">> %02u <<\n", -1);
	// int rres11 = ft_printf(">> %02u <<\n", -1);
	// int rres2 = printf(">> %013u <<\n", UINT_MAX);
	// int rres22 = ft_printf(">> %013u <<\n", UINT_MAX);
	// int rres3 = printf(">> %01x <<\n", 0);
	// int rres33 = ft_printf(">> %01x <<\n", 0);

	// printf("%d\t%d\t%d\n%d\t%d\t%d\n", rres1, rres2, rres3, rres11, rres22, rres33);

	int ares1 = printf(">> %.1u <<\n", 0);
	int ares11 = ft_printf(">> %.1u <<\n", 0);
	int ares2 = printf(">> %.11u <<\n", LONG_MIN);
	int ares22 = ft_printf(">> %.11u <<\n", LONG_MIN);
	int ares3 = printf(">> %.8u %.9u %.10u %.11u %.12u %.13u %.14u<<\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	int ares33 = ft_printf(">> %.8u %.9u %.10u %.11u %.12u %.13u %.14u<<\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf("%d\t%d\t%d\n%d\t%d\t%d\n", ares1, ares2, ares3, ares11, ares22, ares33);

}

