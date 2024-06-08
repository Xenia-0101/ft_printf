/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:31:52 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 14:07:40 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_u(t_mod *mod, unsigned int num)
{
	char c;

	if (!(mod->prec.exists && mod->prec.value == 0 && num == 0))
	{
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
}

static void the_uff(t_mod *mod, unsigned int num, int prec_c, int padd_c)
{
	if (mod->flag.dash)
	{
		pad_space(mod, prec_c, '0');
		ft_putchar_u(mod, num);
		pad_space(mod, padd_c, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			pad_space(mod, padd_c, '0');
		}
		else
		{
			pad_space(mod, padd_c, ' ');
		}
		pad_space(mod, prec_c, '0');
		ft_putchar_u(mod, num);
	}
}


void format_u(t_mod *mod, unsigned int num)
{
	int	char_count;
	int	prec_count;
	int	padding_len;

	char_count = ft_countdigits_u(num);
	prec_count = mod->prec.value - char_count;
	if (prec_count < 0)
		prec_count = 0;
	padding_len = mod->widt.value - char_count - prec_count;
	padding_len += (mod->prec.exists && mod->prec.value == 0 && num == 0);
	the_uff(mod, num, prec_count, padding_len);
}

