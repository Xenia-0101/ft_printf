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

typedef struct s_flag
{
	int	zero;
	int	dash;
	int	spac;
	int	plus;
	int	hash;
}				t_flag;

typedef struct s_format_mod
{
	size_t		total;
	t_flag		flag;
	t_switch	widt;
	t_switch	prec;
	t_switch	spec;
}				t_mod;

typedef struct s_deff_d
{
	int	is_neg;
	int	prec_c;
	int	padd_c;
}		t_deff_d;

int		ft_printf(const char *string, ...);
void	decide_format(t_mod *mod, va_list *vars);
void	pad_space(t_mod *mod, int count, char c);

int		ft_countdigits_d(int n);
int		ft_countdigits_u(unsigned int n);
int		ft_countdigits_x(unsigned int n);
int		ft_countdigits_p(unsigned long n);

void	format_c(t_mod *mod, unsigned char c);
void	format_s(t_mod *mod, char *v_s);
void	format_d(t_mod *mod, int num);
void	format_u(t_mod *mod, unsigned int num);
void	format_x(t_mod *mod, unsigned int num);
void	format_p(t_mod *mod, unsigned long num);
void	format_percent(t_mod *mod);
#endif
