/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:29:39 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 13:31:20 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	ft_putchar_X(t_mod *mod, unsigned int num)
{
	char *base;
	char digit;
	int	m;

	base = ft_strdup("0123456789ABCDEF");
	if (num == 0)
	{
		write(1, "0", 1);
		mod->total++;
	}
	else
	{
		if (num / 16 > 0)
			ft_putchar_X(mod, num / 16);
		m = num % 16;
		digit = base[m];
		write(1, &digit, 1);
		mod->total++;
		num /= 16;
	}
	free(base);

}

void format_X(t_mod *mod, va_list *vars)
{
	unsigned int num;

	num = va_arg(*vars, unsigned int);
	the_ultimate_padding_function(mod, &ft_putchar_X, ft_countdigits_x(num, 0), num);
}

