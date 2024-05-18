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
	return (c == '-' | c == '0');
}

int	ft_countnbr(int n, int count)
{
	if (n < 0)
		n *= -1;
	if (n > 0)
	{
		count++;
		ft_countnbr(n / 10, count);
	}
	else
	{
		return (count);
	}
}

void analyse_mod(t_mod *mod, char *modifier)
{
	int n;

	n = 0;
	if (is_flag(modifier[n]))
	{
		(mod->flag.is_on) = 1;
		(mod->flag.value) = modifier[n];
		n++;
	}
	if (ft_isdigit(modifier[n]))
	{
		(mod->widt.is_on) = 1;
		(mod->widt.value) = ft_atoi(&modifier[n]);
		while (ft_isdigit(modifier[n]))
		{
			n++;
		}
	}
	if (modifier[n] == '.')
	{
		(mod->prec.is_on) = 1;
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
		(mod->spec.is_on) = 1;
		(mod->spec.value) = modifier[n];
	}
}

void init_mod(t_mod *mod)
{
	mod->flag.is_on = 0;
	mod->flag.value = 0;

	mod->widt.is_on = 0;
	mod->widt.value = 0;

	mod->prec.is_on = 0;
	mod->prec.value = 0;

	mod->spec.is_on = 0;
	mod->spec.value = 0;
}

void print_mod(t_mod *mod)
{
	if (mod->flag.is_on)
	{
		printf("mod->flag.value: %c\n", mod->flag.value);
	}
	if (mod->widt.is_on)
	{
		printf("mod->widt.value: %d\n", mod->widt.value);
	}
	if (mod->prec.is_on)
	{
		printf("mod->prec.value: %d\n", mod->prec.value);
	}
	if (mod->spec.is_on)
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
		modifier[n] = start[n--];
	}
	// printf("modifier: %s\n", modifier);
	// analyse modifier
	analyse_mod(mod, modifier);


	return (mod_len);

}

void pad_space(int count, char c)
{
	while (count-- > 0)
	{
		write(1, &c, 1);
	}
}

char *cut_string(char *src, int n)
{
	char *dest;
	int i;

	dest = ft_calloc(n + 1, sizeof (char));
	i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void format_d(t_mod *mod, va_list *vars)
{
	int num;
	int num_len;

	num = va_arg(*vars, int);
	num_len = ft_countnbr(num, 0);
	// printf("Printing num %d which has %d digits\n", num, num_len);
	if (mod->widt.is_on && mod->widt.value > num_len)
		num_len = mod->widt.value;
	// write(1, "Start>", 6);
	if (mod->flag.is_on)
	{
		if (mod->flag.value == '0')
		{
			pad_space(num_len - ft_countnbr(num, 0), '0');
			ft_putnbr_fd(num, 1);
		}
		else if (mod->flag.value == '-')
		{
			ft_putnbr_fd(num, 1);
			pad_space(num_len - ft_countnbr(num, 0), ' ');
		}
	}
	else
	{
		pad_space(num_len - ft_countnbr(num, 0), ' ');
		ft_putnbr_fd(num, 1);
	}
	// write(1, "<End \n", 6);
}

void format_c(t_mod *mod, va_list *vars)
{
	char c;
	int c_len;

	// char is promoted to int when passed through '...'
	c = va_arg(*vars, int);
	c_len = 1;
	if (mod->widt.is_on)
	{
		c_len = mod->widt.value;
	}
	if (mod->flag.is_on)
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
	if (mod->prec.is_on && mod->prec.value < ft_strlen(s))
	{
		s = cut_string(v_s, mod->prec.value);
	}
	else
	{
		s = v_s;
	}
	s_len = ft_strlen(s);
	if (mod->widt.is_on && mod->widt.value > s_len)
		s_len = mod->widt.value;
	// write(1, "Start>", 6);
	if (mod->flag.is_on)
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
	else if (mod->spec.value == 'd')
	{
		format_d(mod, vars);
	}
/* 	else if (mod->spec.value == 'i')
	{
		format_i(mod, vars);
	}
	else if (mod->spec.value == 'x')
	{
		format_x(mod, vars);
	}
	else if (mod->spec.value == 'X')
	{
		format_X(mod, vars);
	} */
}

void ft_printf(char *string, ...)
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
				// get modifier
				// get var
				// write var
				init_mod(&mod);
				n += record_modifier(&mod, (string + n)) + 1;
				format_variable(&mod, &vars);

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
}
