/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:47:46 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_p(t_mod *mod, unsigned long num)
{
	char	*base;
	char	digit;
	int		m;

	base = ft_strdup("0123456789abcdef");
	if (num == 0)
	{
		mod->total += write(1, "0", 1);
	}
	else
	{
		if (num / 16 > 0)
			ft_putchar_p(mod, num / 16);
		m = num % 16;
		digit = base[m];
		mod->total += write(1, &digit, 1);
		num /= 16;
	}
	free(base);
}

static void	ft_putsign(t_mod *mod)
{
	if (mod->flag.plus)
	{
		mod->total += write(1, "+", 1);
	}
	else if (mod->flag.spac)
	{
		mod->total += write(1, " ", 1);
	}
	mod->total += write(1, "0x", 2);
}

static void	the_uff(t_mod *mod, unsigned long num, int prec_c, int padd_c)
{
	if (mod->flag.dash)
	{
		pad_space(mod, prec_c, '0');
		ft_putsign(mod);
		ft_putchar_p(mod, num);
		pad_space(mod, padd_c, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			ft_putsign(mod);
			pad_space(mod, padd_c, '0');
		}
		else
		{
			pad_space(mod, padd_c, ' ');
			ft_putsign(mod);
		}
		pad_space(mod, prec_c, '0');
		ft_putchar_p(mod, num);
	}
}

static void	the_nil_uff(t_mod *mod)
{
	if (mod->flag.dash)
	{
		mod->total += write(1, "(nil)", 5);
		pad_space(mod, mod->widt.value - 5, ' ');
	}
	else
	{
		pad_space(mod, mod->widt.value - 5, ' ');
		mod->total += write(1, "(nil)", 5);
	}
}

void	format_p(t_mod *mod, unsigned long num)
{
	int	char_count;
	int	prec_count;
	int	padding_len;

	if (!num)
	{
		the_nil_uff(mod);
	}
	else
	{
		char_count = ft_countdigits_p(num);
		char_count += 2 + (mod->flag.plus | mod->flag.spac);
		prec_count = mod->prec.value - char_count;
		if (prec_count < 0)
			prec_count = 0;
		padding_len = mod->widt.value - char_count - prec_count;
		the_uff(mod, num, prec_count, padding_len);
	}
}
