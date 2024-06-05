/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_ultimate_padding_function.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:22:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 17:06:11 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void the_ultimate_padding_function(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num)
{
	int char_count;

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
