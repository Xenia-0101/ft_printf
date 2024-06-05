/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:31:52 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/05 12:48:33 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void the_uff(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num)
{
	int char_count;

	// printf("*CHARS: %d*", count);
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


static void ft_putchar_u(t_mod *mod, unsigned int num)
{
	char c;

	if (num == 0)
	{
		mod->total += write(1, "0", 1);
	}
	else
	{
		if (num / 10 > 0)
			ft_putchar_u(mod, num / 10);
		c = num % 10 + '0';
		mod->total += write(1, &c, 1);
		num /= 10;
	}
}


void format_u(t_mod *mod, unsigned int num)
{
	the_uff(mod, &ft_putchar_u, ft_countdigits_u(num), num);
}

