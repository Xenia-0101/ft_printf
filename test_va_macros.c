/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:19:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/27 18:19:30 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Variadic functions are functions that can take a variable
	number of arguments. In C programming, a variadic function
	adds flexibility to the program. It takes one fixed
	argument and then any number of arguments can be passed.
	The variadic function consists of at least one fixed
	variable and then an ellipsis(…) as the last parameter.

	Syntax:

		int function_name(data_type variable_name, ...);

	Values of the passed arguments can be accessed through
	the header file named as:

		#include <stdarg.h>


	va_start
		enables access to variadic function arguments
	(function macro)
	va_arg
		accesses the next variadic function argument
	(function macro)
	va_end
		ends traversal of the variadic function arguments
	(function macro)
	va_copy
		The va_copy macro copies src to dest.
		-	va_end should be called on dest before the
			function returns or any subsequent re-initialization
			of dest (via calls to va_start or va_copy).
*/

#include <stdio.h>
#include <stdarg.h>

int	sum(int n, ...)
{
	va_list	nums;
	int		total;

	total = 0;
	va_start(nums, n);
	while(n-- > 0)
		total += va_arg(nums, int);
	va_end(nums);
	return total;
}

int	main(void)
{
	int	a = 5;
	int	b = 10;
	int	c = 15;
	int	res;

	res = sum(3, a, b, c);
	printf("The sum of %d, %d and %d is %d\n", a, b, c, res);
	return (0);
}





















