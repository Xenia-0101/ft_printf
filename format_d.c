/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:35:22 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 14:05:14 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_d(t_mod *mod, int num)
{
	char	c;
	if (!(mod->prec.exists && mod->prec.value == 0 && num == 0))
	{
		if (num == 0)
			mod->total += write(1, "0", 1);
		else if (num == -2147483648)
			mod->total += write(1, "2147483648", 10);
		else if (num < 0)
		{
			mod->total += write(1, "-", 1);
			ft_putchar_d(mod, -1 * num);
		}
		else
		{
			if (num / 10 > 0)
				ft_putchar_d(mod, num / 10);
			c = num % 10 + '0';
			mod->total += write(1, &c, 1);
			num /= 10;
		}
	}
}

static void	ft_put_sign(t_mod *mod, int is_neg)
{
	if (is_neg)
	{
		mod->total += write(1, "-", 1);
	}
	else if (mod->flag.plus)
	{
		mod->total += write(1, "+", 1);
	}
	else if (mod->flag.spac)
	{
		mod->total += write(1, " ", 1);
	}
}
static void	the_uff(t_mod *mod, int num, int is_neg, int prec_c, int padd_c)
{
	if (mod->flag.dash)
	{
		ft_put_sign(mod, is_neg);
		pad_space(mod, prec_c, '0');
		ft_putchar_d(mod, num);
		pad_space(mod, padd_c, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			ft_put_sign(mod, is_neg);
			pad_space(mod, padd_c, '0');
		}
		else
		{
			pad_space(mod, padd_c, ' ');
			ft_put_sign(mod, is_neg);
		}
		pad_space(mod, prec_c, '0');
		ft_putchar_d(mod, num);
	}
}

void	format_d(t_mod *mod, int num)
{
	int	char_count;
	int	prec_count;
	int	padding_len;
	int	is_neg;

	is_neg = 0;
	if (num < 0)
	{
		num *= -1;
		is_neg = 1;
	}
	char_count = ft_countdigits_d(num) + (is_neg | mod->flag.plus | mod->flag.spac);
	prec_count = mod->prec.value - char_count + is_neg;
	if (prec_count < 0)
		prec_count = 0;
	padding_len = mod->widt.value - char_count - prec_count;
	padding_len += (mod->prec.exists && mod->prec.value == 0 && num == 0);
	the_uff(mod, num, is_neg, prec_count, padding_len);
}

