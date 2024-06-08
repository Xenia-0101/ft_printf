/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:35:22 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 22:51:40 by xvislock         ###   ########.fr       */
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

static void	the_uff(t_mod *mod, t_deff_d *deff_d, int num)
{
	if (mod->flag.dash)
	{
		ft_put_sign(mod, deff_d->is_neg);
		pad_space(mod, deff_d->prec_c, '0');
		ft_putchar_d(mod, num);
		pad_space(mod, deff_d->padd_c, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			ft_put_sign(mod, deff_d->is_neg);
			pad_space(mod, deff_d->padd_c, '0');
		}
		else
		{
			pad_space(mod, deff_d->padd_c, ' ');
			ft_put_sign(mod, deff_d->is_neg);
		}
		pad_space(mod, deff_d->prec_c, '0');
		ft_putchar_d(mod, num);
	}
}

void	format_d(t_mod *mod, int num)
{
	t_deff_d	deff_d;
	int			char_count;

	deff_d.is_neg = 0;
	deff_d.prec_c = 0;
	deff_d.padd_c = 0;
	if (num < 0)
	{
		num *= -1;
		deff_d.is_neg = 1;
	}
	char_count = ft_countdigits_d(num);
	char_count += (deff_d.is_neg | mod->flag.plus | mod->flag.spac);
	deff_d.prec_c = mod->prec.value - char_count + deff_d.is_neg;
	if (deff_d.prec_c < 0)
		deff_d.prec_c = 0;
	deff_d.padd_c = mod->widt.value - char_count - deff_d.prec_c;
	deff_d.padd_c += (mod->prec.exists && mod->prec.value == 0 && num == 0);
	the_uff(mod, &deff_d, num);
}
