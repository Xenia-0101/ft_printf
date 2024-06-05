/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:13:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 15:36:30 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void decide_format(t_mod *mod, va_list *vars)
{
	if (mod->spec.value == 's')
	{
		format_s(mod, vars);
	}
	else if (mod->spec.value == 'c')
	{
		format_c(mod, vars);
	}
	else if (mod->spec.value == 'p')
	{
		format_p(mod, vars);
	}
	else if (mod->spec.value == 'd' || mod->spec.value == 'i')
	{
		format_d(mod, vars);
	}
	else if (mod->spec.value == 'u')
	{
		format_u(mod, vars);
	}
	else if (mod->spec.value == 'x')
	{
		format_x(mod, vars);
	}
	else if (mod->spec.value == 'X')
	{
		format_X(mod, vars);
	}
}
