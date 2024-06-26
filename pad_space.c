/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:24:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:54:11 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_space(t_mod *mod, int count, char c)
{
	while (count-- > 0)
	{
		write(1, &c, 1);
		mod->total++;
	}
}
