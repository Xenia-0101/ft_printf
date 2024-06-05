/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:37:25 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/01 19:37:10 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countdigits_u(unsigned int n, int count)
{
	if (n == 4294967295)
		return (10);
	if (n)
		count++;
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

