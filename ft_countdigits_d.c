/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:39:22 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 19:19:55 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_countdigits_d(int n, int count)
{
	if (n == -2147483648)
		return (10);
	if (n)
		count++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

