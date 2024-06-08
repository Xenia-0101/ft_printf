/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:34:10 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:44:08 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_c(t_mod *mod, unsigned char c)
{
	int	c_len;

	c_len = 1;
	if (mod->widt.exists)
	{
		c_len = mod->widt.value;
	}
	if (mod->flag.dash)
	{
		mod->total += write(1, &c, 1);
		pad_space(mod, c_len - 1, ' ');
	}
	else
	{
		pad_space(mod, c_len - 1, ' ');
		mod->total += write(1, &c, 1);
	}
}
