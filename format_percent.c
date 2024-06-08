/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:49:04 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/08 21:48:03 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_percent(t_mod *mod)
{
	mod->total += write(1, "%", 1);
}
