/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:21:01 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/06 21:55:31 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void the_uff(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num)
{
	int char_count; 

	char_count = count;
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	int padding_len = mod->widt.value - char_count;
	if (mod->flag.dash)
	{
			pad_space(mod, mod->prec.value - count, '0');
			f(mod, num);
			pad_space(mod, padding_len, ' ');
	}
	else
	{
		if (mod->flag.zero)
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
static void	ft_putchar_x(t_mod *mod, unsigned int num)
{
	char *base;
	char digit;
	int	m;

	if (mod->spec.value == 'X')
		base = ft_strdup("0123456789ABCDEF");
	else
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
	free(base);
}


void format_x(t_mod *mod, unsigned int num)
{
	// unsigned int num;

	// num = va_arg(*vars, unsigned int);
	the_ultimate_padding_function(mod, &ft_putchar_x, ft_countdigits_x(num), num);
}
