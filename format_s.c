/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:16:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/05 10:31:08 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void format_s(t_mod *mod, char *v_s)
{
	char *s;
	int s_len;
	int to_free = 0;

	if (!v_s)
	{
		mod->total += write(1, "(null)", 6);
		return ;
	}
	if (mod->prec.exists && mod->prec.value < ft_strlen(v_s))
	{
		s = ft_calloc(mod->prec.value + 1, sizeof (char));
		ft_memmove(s, v_s, mod->prec.value);
		to_free = 1;
	}
	else
	{
		s = v_s;
	}
	s_len = ft_strlen(s);
	if (mod->widt.exists && mod->widt.value > s_len)
		s_len = mod->widt.value;
	if (mod->flag.exists)
	{
		if (mod->flag.value == '-')
		{
			write(1, s, ft_strlen(s));
			mod->total += ft_strlen(s);
			pad_space(mod, s_len - ft_strlen(s), ' ');
		}
		else
		{
			pad_space(mod, s_len - ft_strlen(s), ' ');
			write(1, s, ft_strlen(s));
			mod->total += ft_strlen(s);
		}
	}
	else
	{
		pad_space(mod, s_len - ft_strlen(s), ' ');
		write(1, s, ft_strlen(s));
		mod->total += ft_strlen(s);
	}
	if (to_free)
	free(s);

}
