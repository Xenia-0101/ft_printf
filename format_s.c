/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:16:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:48:45 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	the_uff(t_mod *mod, char *s, int char_c, int padd_c)
{
	if (mod->flag.dash)
	{
		mod->total += write(1, s, char_c);
		pad_space(mod, padd_c, ' ');
	}
	else
	{
		pad_space(mod, padd_c, ' ');
		mod->total += write(1, s, char_c);
	}
}

static void	the_null_uff(t_mod *mod)
{
	if (mod->prec.exists && mod->prec.value < 5)
	{
		pad_space(mod, mod->widt.value, ' ');
	}
	else
	{
		if (mod->flag.dash)
		{
			mod->total += write(1, "(null)", 6);
			pad_space(mod, mod->widt.value - 6, ' ');
		}
		else
		{
			pad_space(mod, mod->widt.value - 6, ' ');
			mod->total += write(1, "(null)", 6);
		}
	}
}

void	format_s(t_mod *mod, char *s)
{
	int		char_count;
	int		padding_len;

	if (!s)
		the_null_uff(mod);
	else
	{
		char_count = ft_strlen(s);
		if (mod->prec.exists && mod->prec.value < char_count)
			char_count = mod->prec.value;
		padding_len = mod->widt.value - char_count;
		the_uff(mod, s, char_count, padding_len);
	}
}
