/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:21:01 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 14:07:18 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_x(t_mod *mod, unsigned int num)
{
	char	base[17];
	char	digit;
	int		m;

	if (!(mod->prec.exists && mod->prec.value == 0 && num == 0))
	{
		if (mod->spec.value == 'X')
			ft_strlcpy(base, "0123456789ABCDEF", 17);
		else
			ft_strlcpy(base, "0123456789abcdef", 17);
		if (num == 0)
		{
			mod->total += write(1, "0", 1);
		}
		else
		{
			if (num / 16 > 0)
				ft_putchar_x(mod, num / 16);
			m = num % 16;
			digit = base[m];
			mod->total += write(1, &digit, 1);
			num /= 16;
		}
	}
}

static void	the_uff(t_mod *mod, unsigned int num, char *h, int prec_c, int padd_c)
{
	if (mod->flag.dash)
	{
		if (mod->flag.hash && num != 0)
			mod->total += write(1, h, 2);
		pad_space(mod, prec_c, '0');
		ft_putchar_x(mod, num);
		pad_space(mod, padd_c, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			if (mod->flag.hash && num != 0)
				mod->total += write(1, h, 2);
			pad_space(mod, padd_c, '0');
		}
		else
		{
			pad_space(mod, padd_c, ' ');
			if (mod->flag.hash && num != 0)
				mod->total += write(1, h, 2);
		}
		pad_space(mod, prec_c, '0');
		ft_putchar_x(mod, num);
	}
}


void	format_x(t_mod *mod, unsigned int num)
{
	int		char_count;
	int		prec_count;
	int		padding_len;
	char	hash[3];
	char	*p_hash;

	if (mod->spec.value == 'X')
		ft_strlcpy(hash, "0X", 3);
	else
		ft_strlcpy(hash, "0x", 3);
	p_hash = &hash[0];

	char_count = ft_countdigits_x(num) + 2 * mod->flag.hash;
	prec_count = mod->prec.value - ft_countdigits_x(num);
	if (prec_count < 0)
		prec_count = 0;
	padding_len = mod->widt.value - prec_count - char_count;
	padding_len += (mod->prec.exists && mod->prec.value == 0 && num == 0);
	// printf("\n\n%d\t%d\t%d\n\n", char_count, prec_count, padding_len);
	the_uff(mod, num, p_hash, prec_count, padding_len);
}
