/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:26:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/05 09:35:12 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_countdigits_x(unsigned int n, int count)
{
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}
