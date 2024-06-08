/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:13:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:42:09 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decide_format(t_mod *mod, va_list *vars)
{
	if (mod->spec.value == 's')
		format_s(mod, va_arg(*vars, char *));
	else if (mod->spec.value == 'c')
		format_c(mod, va_arg(*vars, int));
	else if (mod->spec.value == 'p')
		format_p(mod, va_arg(*vars, unsigned long));
	else if (mod->spec.value == 'd' || mod->spec.value == 'i')
		format_d(mod, va_arg(*vars, int));
	else if (mod->spec.value == 'u')
		format_u(mod, va_arg(*vars, unsigned int));
	else if ((mod->spec.value == 'x') | (mod->spec.value == 'X'))
		format_x(mod, va_arg(*vars, unsigned int));
	else if ((mod->spec.value == '%'))
		format_percent(mod);
}
