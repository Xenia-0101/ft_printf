/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:32:45 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/30 21:32:45 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create a function which accepts a string and (...) and loops through the string,
// determinig if a char is a modifier or not
//
// if a modifier is found, loop until specifier is found
// call function which determines the format
// print (...)

#include <libft.h>
#include "../includes/ft_printf.h"

int is_specifier(char c)
{
	char	*specs = "cspdiuxX";
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c == specs[i++])
			return (1);
	}
	return (0);
}

char *record_modifier(char **string)
{
	char	*start;
	int		n;

	start = ft_strchr(*string, '%');
	if (start == NULL)
		return (NULL);
	else if (*(++start) == '%')
		write(1,"\x1b[1;31m%\t", 9);

}

void ft_printf(char *string, char *var_1, char *var_2)
{
	// get modifiers
	record_modifier(&string);

}

int	main(void)
{
	ft_printf("Hello %s, the answer is %-15d.\n", "You", "42");

	return (0);
}
