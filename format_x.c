/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:21:01 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/07 20:02:42 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void the_uff(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num)
{
	int char_count;
	int padding_len;
	char hash[3];

	if (mod->spec.value == 'X')
		ft_strlcpy(hash, "0X", 3);
	else
		ft_strlcpy(hash, "0x", 3);

	if (mod->flag.hash)
		count += 2;
	char_count = count;
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > char_count)
		char_count = mod->prec.value;
	char_count += mod->flag.plus | mod->flag.spac;
	// account for width - add padding to the number
	padding_len = mod->widt.value - char_count;
	// printf("\n\n%d\t%d\t%d\n\n", mod->prec.value, char_count, padding_len);
	if (mod->flag.dash)
	{
		if (mod->flag.plus)
		{
			mod->total += write(1, "+", 1);
		}
		else if (mod->flag.spac)
		{
			mod->total += write(1, " ", 1);
		}
		if (mod->flag.hash)
			mod->total += write(1, hash, 2);
		pad_space(mod, mod->prec.value - count, '0');
		f(mod, num);
		pad_space(mod, padding_len, ' ');
	}
	else
	{
		if (mod->flag.zero)
		{
			if (mod->flag.plus)
			{
				mod->total += write(1, "+", 1);
			}
			else if (mod->flag.spac)
			{
				mod->total += write(1, " ", 1);
			}
			if (mod->flag.hash)
				mod->total += write(1, hash, 2);
			pad_space(mod, padding_len, '0');
		}
		else
		{
			// THIS NEEDS TO BE CORRECTED IN A NORMAL WAY !!!!!
			if (mod->flag.hash)
				pad_space(mod, padding_len - 2, ' ');
			else
				pad_space(mod, padding_len, ' ');
			// ^ ^ ^
			// | | |
			if (mod->flag.plus)
			{
				mod->total += write(1, "+", 1);
			}
			else if (mod->flag.spac)
			{
				mod->total += write(1, " ", 1);
			}
			if (mod->flag.hash)
				mod->total += write(1, hash, 2);
		}
		if (mod->flag.hash)
			pad_space(mod, mod->prec.value - count + 2, '0');
		else
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
	the_uff(mod, &ft_putchar_x, ft_countdigits_x(num), num);
}
