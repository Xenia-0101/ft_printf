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
	int		exists;
	int		value;
}			t_switch;

typedef struct s_format_mod
{
	size_t		total;
	t_switch	flag;
	t_switch	widt;
	t_switch	prec;
	t_switch	spec;
}	t_mod;

int		ft_printf(const char *string, ...);
void	decide_format(t_mod *mod, va_list *vars);
void	the_ultimate_padding_function(t_mod *mod, void (*f)(t_mod *, unsigned int), int count, unsigned int num);
void	pad_space(t_mod *mod, int count, char c);

int		ft_countdigits_d(int n);
int		ft_countdigits_u(unsigned int n);
int		ft_countdigits_x(unsigned int n);
int		ft_countdigits_p(unsigned long n);

void	format_c(t_mod *mod, char c);
void	format_s(t_mod *mod, char *v_s);
void	format_d(t_mod *mod, int num);
void	format_u(t_mod *mod, unsigned int num);
void	format_x(t_mod *mod, unsigned int num);
void	format_p(t_mod *mod, unsigned long num);
#endif
