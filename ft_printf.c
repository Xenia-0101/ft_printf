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

void ft_putchar_u(t_mod *mod, unsigned int num)
{
	char c;

	if (num == 0)
	{
		write(1, "0", 1);
		mod->total++;
	}
	else
	{
		if (num / 10 > 0)
			ft_putchar_u(mod, num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
		mod->total++;
		num /= 10;
	}
}

void	ft_putchar_d(t_mod *mod, int num)
{
		char c;

	if (num == 0)
	{
		write(1, "0", 1);
		mod->total++;
	}
	else if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		mod->total += 11;
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		mod->total++;
		ft_putchar_d(mod, -1 * num);
	}
	else
	{
		if (num / 10 > 0)
			ft_putchar_u(mod, num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
		mod->total++;
		num /= 10;
	}
}

void	ft_putchar_x(t_mod *mod, unsigned int num)
{
	char *base;
	char digit;
	int	m;

	base = ft_strdup("0123456789abcdef");
	if (num == 0)
	{
		write(1, "0", 1);
		mod->total++;
	}
	else
	{
		if (num / 16 > 0)
			ft_putchar_x(mod, num / 16);
		m = num % 16;
		digit = base[m];
		write(1, &digit, 1);
		mod->total++;
		num /= 16;
	}

}

void	ft_putchar_X(t_mod *mod, unsigned int num)
{
	char *base;
	char digit;
	int	m;

	base = ft_strdup("0123456789ABCDEF");
	if (num == 0)
	{
		write(1, "0", 1);
		mod->total++;
	}
	else
	{
		if (num / 16 > 0)
			ft_putchar_X(mod, num / 16);
		m = num % 16;
		digit = base[m];
		write(1, &digit, 1);
		mod->total++;
		num /= 16;
	}

}

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

int	ft_countdigits(int n, int count)
{
	if (n)
		count++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_countdigits_u(unsigned int n, int count)
{
	if (n)
		count++;
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int ft_countdigits_x(unsigned int n, int count)
{
	if (n)
		count++;
	while (n / 16 > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
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

void pad_space(t_mod *mod, int count, char c)
{
	// printf("padding count: %d\n", count);
	while (count-- > 0)
	{
		write(1, &c, 1);
		mod->total++;
	}
}

char *cut_string(char *src, int n)
{
	int i;
	char *dest;

	i = 0;
	dest = ft_calloc(n + 1, sizeof (char));
	if (dest == NULL)
		return NULL;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void the_ultimate_padding_function(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num)
{
	int char_count;

	char_count = count;
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	int padding_len = mod->widt.value - char_count;
	if (mod->flag.exists && mod->flag.value == '-')
	{
			pad_space(mod, mod->prec.value - count, '0');
			f(mod, num);
			pad_space(mod, padding_len, ' ');
	}
	else
	{
		if (mod->flag.exists && mod->flag.value == '0')
		{
			pad_space(mod, padding_len, '0');
		}
		else
		{
			pad_space(mod, padding_len, ' ');
		}
		pad_space(mod, mod->prec.value - count, '0');
		f(mod, num);
	}

}

void format_d(t_mod *mod, va_list *vars)
{
	int num;
	int digit_count;
	int char_count;
	int is_neg;

	num = va_arg(*vars, int);
	// account for number of digits in the number
	digit_count = ft_countdigits(num, 0);
	char_count = digit_count;
	// printf("Printing num %d which has %d digits\n", num, digit_count);

	// account for negative numbers
	is_neg = 0;
	if (num < 0)
	{
		num *= -1;
		is_neg = 1;
		mod->prec.value++;
	}
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > digit_count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	int padding_len = mod->widt.value - char_count;
	if (mod->flag.exists && mod->flag.value == '-')
	{
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
			pad_space(mod, mod->prec.value - digit_count, '0');
			ft_putchar_d(mod, num);
			pad_space(mod, padding_len, ' ');
	}
	else
	{
		if (mod->flag.exists && mod->flag.value == '0')
		{
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
			pad_space(mod, padding_len, '0');
		}
		else
		{
			pad_space(mod, padding_len, ' ');
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
		}
		pad_space(mod, mod->prec.value - digit_count, '0');
		ft_putchar_d(mod, num);
	}
}

void format_c(t_mod *mod, va_list *vars)
{
	char c;
	int c_len;

	// char is promoted to int when passed through '...'
	c = va_arg(*vars, int);
	c_len = 1;
	if (mod->widt.exists)
	{
		c_len = mod->widt.value;
	}
	if (mod->flag.exists)
	{
		if (mod->flag.value == '0')
		{
			write(1, "0 flag used with c specifier.", 29);
			return ;
		}
		write(1, &c, 1);
		mod->total++;
		pad_space(mod, c_len - 1, ' ');
	}
	else
	{
		pad_space(mod, c_len - 1, ' ');
		write(1, &c, 1);
		mod->total++;
	}
}


void format_s(t_mod *mod, va_list *vars)
{
	char *v_s;
	char *s;
	int s_len;

	v_s = va_arg(*vars, char *);
	if (mod->prec.exists && mod->prec.value < ft_strlen(v_s))
	{
		s = cut_string(v_s, mod->prec.value);
	}
	else
	{
		s = v_s;
	}
	s_len = ft_strlen(s);
	if (mod->widt.exists && mod->widt.value > s_len)
		s_len = mod->widt.value;
	// write(1, "Start>", 6);
	if (mod->flag.exists)
	{
		if (mod->flag.value == '-')
		{
			write(1, s, ft_strlen(s));
			mod->total += ft_strlen(s);
			pad_space(mod, s_len - ft_strlen(s), ' ');
		}
		else
		{
			pad_space(mod, s_len - ft_strlen(s), ' ');
			write(1, s, ft_strlen(s));
			mod->total += ft_strlen(s);
		}
	}
	else
	{
		pad_space(mod, s_len - ft_strlen(s), ' ');
		write(1, s, ft_strlen(s));
		mod->total += ft_strlen(s);
	}
	// write(1, "<End \n", 6);
}

/* void format_p(t_mod *mod, va_list *vars)
{


} */

void format_u(t_mod *mod, va_list *vars)
{
	unsigned int num;

	num = va_arg(*vars, unsigned int);
	the_ultimate_padding_function(mod, &ft_putchar_u, ft_countdigits_u(num, 0), num);
}

void format_x(t_mod *mod, va_list *vars)
{
	unsigned int num;

	num = va_arg(*vars, unsigned int);
	the_ultimate_padding_function(mod, &ft_putchar_x, ft_countdigits_x(num, 0), num);
}

void format_X(t_mod *mod, va_list *vars)
{
	unsigned int num;

	num = va_arg(*vars, unsigned int);
	the_ultimate_padding_function(mod, &ft_putchar_X, ft_countdigits_x(num, 0), num);
}

void format_variable(t_mod *mod, va_list *vars)
{
	if (mod->spec.value == 's')
	{
		format_s(mod, vars);
	}
	else if (mod->spec.value == 'c')
	{
		format_c(mod, vars);
	}
/* 	else if (mod->spec.value == 'p')
	{
		format_p(mod, vars);
	} */
	else if (mod->spec.value == 'd' || mod->spec.value == 'i')
	{
		format_d(mod, vars);
	}
	else if (mod->spec.value == 'u')
	{
		format_u(mod, vars);
	}
	else if (mod->spec.value == 'x')
	{
		format_x(mod, vars);
	}
	else if (mod->spec.value == 'X')
	{
		format_X(mod, vars);
	}
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
				n++;
			}
			else
			{
				n += record_modifier(mod, (string + n)) + 1;
				// print_mod(mod);
				format_variable(mod, &vars);
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
