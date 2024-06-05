/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:16:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 19:41:25 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *cut_string(char *src, int n)
{
	int i;
	char *dest;

	i = 0;
	dest = ft_calloc(n + 1, sizeof (char));
	if (dest == NULL)
		return NULL;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void format_s(t_mod *mod, va_list *vars)
{
	char *v_s;
	char *s;
	int s_len;

	v_s = va_arg(*vars, char *);
	if (!v_s)
	{
		mod->total += write(1, "(null)", 6);
		return ;
	}
	if (mod->prec.exists && mod->prec.value < ft_strlen(v_s))
	{
		s = cut_string(v_s, mod->prec.value);
	}
	else
	{
		s = v_s;
	}
	s_len = ft_strlen(s);
	if (mod->widt.exists && mod->widt.value > s_len)
		s_len = mod->widt.value;
	// write(1, "Start>", 6);
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
	// write(1, "<End \n", 6);
	// free(s);
}
