/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/05 12:43:57 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void the_uff(t_mod *mod, void (*f)(t_mod *, unsigned long), int count, unsigned long num)
{
	int char_count;
	int padding_len;

	char_count = count + 2;
	// account for precision - determine min number of digits printed
	if (mod->prec.exists && mod->prec.value > count)
		char_count = mod->prec.value;

	// account for width - add padding to the number
	padding_len = mod->widt.value - char_count;
	if (mod->flag.exists && mod->flag.value == '-')
	{
			pad_space(mod, mod->prec.value - count, '0');
			mod->total += write(1, "0x", 2);
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
		mod->total += write(1, "0x", 2);
		f(mod, num);
	}
}


static void	ft_putchar_p(t_mod *mod, unsigned long num)
{
	char *base;
	char digit;
	int	m;

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
void format_p(t_mod *mod, unsigned long num)
{
	;

	// num = va_arg(*vars, unsigned long);
	if (!num)
	{
		mod->total += write(1, "(nil)", 5);
		return ;
	}

	// printf("digits: %d\n", ft_countdigits_p(num));
	the_uff(mod, &ft_putchar_p, ft_countdigits_p(num), num);
}
