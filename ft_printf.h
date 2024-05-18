/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:29:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/10 20:29:27 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_switch
{
	int		is_on;
	int		value;
}	t_switch;

typedef struct s_format_mod
{
	t_switch	flag;
	t_switch	widt;
	t_switch	prec;
	t_switch	spec;
}	t_mod;

typedef struct s_format_data
{
	t_mod		modifier;
	char		*value;
}	t_data;


void ft_printf(char *string, ...);
// int ft_printf(void);

#endif
