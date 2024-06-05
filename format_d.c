/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:35:22 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/05 20:03:52 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_d(t_mod *mod, int num)
{
	char c;

	if (num == 0)
	{
		mod->total += write(1, "0", 1);
	}
	else if (num == -2147483648)
	{
		mod->total += write(1, "2147483648", 10);
	}
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

void format_d(t_mod *mod, int num)
{
	int digit_count;
	int char_count;
	int is_neg;
	int padding_len;

	// account for number of digits in the number
	digit_count = ft_countdigits_d(num);
	char_count = digit_count;
	
	// account for negative numbers
	is_neg = 0;
	if (num < 0)
	{
		num *= -1;
		is_neg = 1;
		mod->prec.value++;
	}
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > digit_count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	padding_len = mod->widt.value - char_count;
	if (mod->flag.exists && mod->flag.value == '-')
	{
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
			pad_space(mod, mod->prec.value - digit_count, '0');
			ft_putchar_d(mod, num);
			pad_space(mod, padding_len, ' ');
	}
	else
	{
		if (mod->flag.exists && mod->flag.value == '0')
		{
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
			pad_space(mod, padding_len, '0');
		}
		else
		{
			pad_space(mod, padding_len, ' ');
			if (is_neg)
			{
				write(1, "-", 1);
				mod->total++;
			}
		}
		pad_space(mod, mod->prec.value - digit_count, '0');
		ft_putchar_d(mod, num);
	}
}

