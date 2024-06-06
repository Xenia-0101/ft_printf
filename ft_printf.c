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


// #include <limits.h>
// int main(void)
// {
// 	printf("> %d <\n", 0);
// 	ft_printf("> %d <\n\n", 0);
// 	printf("> %d <\n", -1);
// 	ft_printf("> %d <\n\n", -1);
// 	printf("> %d <\n", 1);
// 	ft_printf("> %d <\n\n", 1);
// 	printf("> %d <\n", 9);
// 	ft_printf("> %d <\n\n", 9);
// 	printf("> %d <\n", 10);
// 	ft_printf("> %d <\n\n", 10);
// 	printf("> %d <\n", 11);
// 	ft_printf("> %d <\n\n", 11);
// 	printf("> %d <\n", 15);
// 	ft_printf("> %d <\n\n", 15);
// 	printf("> %d <\n", 16);
// 	ft_printf("> %d <\n\n", 16);
// 	printf("> %d <\n", 17);
// 	ft_printf("> %d <\n\n", 17);
// 	printf("> %d <\n", 99);
// 	ft_printf("> %d <\n\n", 99);
// 	printf("> %d <\n", 100);
// 	ft_printf("> %d <\n\n", 100);
// 	printf("> %d <\n", 101);
// 	ft_printf("> %d <\n\n", 101);
// 	printf("> %d <\n", -9);
// 	ft_printf("> %d <\n\n", -9);
// 	printf("> %d <\n", -10);
// 	ft_printf("> %d <\n\n", -10);
// 	printf("> %d <\n", -11);
// 	ft_printf("> %d <\n\n", -11);
// 	printf("> %d <\n", -14);
// 	ft_printf("> %d <\n\n", -14);
// 	printf("> %d <\n", -15);
// 	ft_printf("> %d <\n\n", -15);
// 	printf("> %d <\n", -16);
// 	ft_printf("> %d <\n\n", -16);
// 	printf("> %d <\n", -99);
// 	ft_printf("> %d <\n\n", -99);
// 	printf("> %d <\n", -100);
// 	ft_printf("> %d <\n\n", -100);
// 	printf("> %d <\n", -101);
// 	ft_printf("> %d <\n\n", -101);
// 	printf("> %d <\n", INT_MAX);
// 	ft_printf("> %d <\n\n", INT_MAX);
// 	printf("> %d <\n", INT_MIN);
// 	ft_printf("> %d <\n\n", INT_MIN);
// 	printf("> %d <\n", LONG_MAX);
// 	ft_printf("> %d <\n\n", LONG_MAX);
// 	printf("> %d <\n", LONG_MIN);
// 	ft_printf("> %d <\n\n", LONG_MIN);
// 	printf("> %d <\n", UINT_MAX);
// 	ft_printf("> %d <\n\n", UINT_MAX);
// 	printf("> %d <\n", ULONG_MAX);
// 	ft_printf("> %d <\n\n", ULONG_MAX);
// 	printf("> %d <\n", 9223372036854775807LL);
// 	ft_printf("> %d <\n\n", 9223372036854775807LL);
// 	printf("> %d %d %d %d %d %d %d<\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	ft_printf("> %d %d %d %d %d %d %d<\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);



// 	printf("> %.2d <\n", -1);
// 	ft_printf("> %.2d <\n\n", -1);
// 	printf("> %.1d <\n", -9);
// 	ft_printf("> %.1d <\n\n", -9);

// 	return (0);
// }



