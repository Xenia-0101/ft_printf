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

void ft_putchar_u(unsigned int num)
{
	char c;

	if (num == 0)
		write(1, "0", 1);
	else
	{
		if (num / 10 > 0)
			ft_putchar_u(num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
		num /= 10;
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
	return (c == '-' | c == '0');
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
	mod->flag.exists = 0;
	mod->flag.value = 0;

	mod->widt.exists = 0;
	mod->widt.value = 0;

	mod->prec.exists = 0;
	mod->prec.value = 0;

	mod->spec.exists = 0;
	mod->spec.value = 0;
}

void free_mod(t_mod *mod)
{
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

int record_modifier(t_mod *mod, char *string)
{
	int n;
	int mod_len;
	char *start;
	char *modifier;

	mod_len = 0;
	n = 0;
	start = ft_strchr(string, '%');
	// get char count of modifier
	while (!is_specifier(start[n]))
	{
		mod_len++;
		n++;
	}
	// printf("\nchars in modifier: %d\n", mod_len);
	modifier = ft_calloc(mod_len, sizeof (char));
	n = mod_len;
	while (n > 0)
	{
		modifier[n] = start[n--];			// !! why does it not work when n-- is on the new line
	}
	// printf("modifier: %s\n", modifier);
	// analyse modifier
	analyse_mod(mod, modifier);


	return (mod_len);

}

void pad_space(int count, char c)
{
	// printf("padding count: %d\n", count);
	while (count-- > 0)
	{
		write(1, &c, 1);
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
				write(1, "-", 1);
			pad_space(mod->prec.value - digit_count, '0');
			ft_putnbr_fd(num, 1);
			pad_space(padding_len, ' ');
	}
	else
	{
		if (mod->flag.exists && mod->flag.value == '0')
		{
			if (is_neg)
				write(1, "-", 1);
			pad_space(padding_len, '0');
		}
		else
		{
			pad_space(padding_len, ' ');
			if (is_neg)
				write(1, "-", 1);
		}
		pad_space(mod->prec.value - digit_count, '0');
		ft_putnbr_fd(num, 1);
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
		pad_space(c_len - 1, ' ');
	}
	else
	{
		pad_space(c_len - 1, ' ');
		write(1, &c, 1);
	}
}


void format_s(t_mod *mod, va_list *vars)
{
	char *v_s;
	char *s;
	int s_len;

	v_s = va_arg(*vars, char *);
	if (mod->prec.exists && mod->prec.value < ft_strlen(s))
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
			pad_space(s_len - ft_strlen(s), ' ');
		}
		else
		{
			pad_space(s_len - ft_strlen(s), ' ');
			write(1, s, ft_strlen(s));
		}
	}
	else
	{
		pad_space(s_len - ft_strlen(s), ' ');
		write(1, s, ft_strlen(s));
	}
	// write(1, "<End \n", 6);
}

void format_p(t_mod *mod, va_list *vars)
{
}

void format_u(t_mod *mod, va_list *vars)
{
	unsigned int num;
	int digit_count;
	int char_count;
	int is_neg;

	num = va_arg(*vars, unsigned int);
	// account for number of digits in the number
	digit_count = ft_countdigits(num, 0);
	char_count = digit_count;
	// printf("Printing num %d which has %d digits\n", num, digit_count);

	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > digit_count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	int padding_len = mod->widt.value - char_count;
	if (mod->flag.exists && mod->flag.value == '-')
	{
			pad_space(mod->prec.value - digit_count, '0');
			ft_putnbr_fd(num, 1);
			pad_space(padding_len, ' ');
	}
	else
	{
		if (mod->flag.exists && mod->flag.value == '0')
		{
			pad_space(padding_len, '0');
		}
		else
		{
			pad_space(padding_len, ' ');
		}
		pad_space(mod->prec.value - digit_count, '0');
		ft_putchar_u(num);
	}




		//ft_putnbr_fd(num, 1);
	//}
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
	else if (mod->spec.value == 'p')
	{
		format_p(mod, vars);
	}
	else if (mod->spec.value == 'd' || mod->spec.value == 'i')
	{
		format_d(mod, vars);
	}
	else if (mod->spec.value == 'u')
	{
		format_u(mod, vars);
	}
/*	else if (mod->spec.value == 'x')
	{
		format_x(mod, vars);
	}
	else if (mod->spec.value == 'X')
	{
		format_X(mod, vars);
	} */
}

int ft_printf(char *string, ...)
{
	int n;
	va_list vars;
	t_mod mod;
	int buff_1;
	char *buff_2;

	va_start(vars, string);
	// printf("The first param: %s\n", string);
	// printf("%15d\n", 42);

	n = 0;
	while (string[n])
	{
		if (string[n] == '%')
		{
			if (string[n + 1] == '%')
			{
				write(1, &string[n], 1);
				n++;
			}
			else
			{
				init_mod(&mod);
				n += record_modifier(&mod, (string + n)) + 1;
				// write(1, "\n", 1);
				// write(1, &mod.spec.value, sizeof(mod.spec.value));
				// write(1, "\n", 1);
				format_variable(&mod, &vars);
				free_mod(&mod);

				// print_mod(&mod);
			}
		}
		else
		{
			write(1, &string[n], 1);
			n++;
		}
	}
	va_end(vars);
	return (5);
}
