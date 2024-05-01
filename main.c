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

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_strlen(char *str);
static char	*ft_strchr(const char *s, int c);

size_t specs_count_util(const char *format)
{
	size_t count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count++;
			format++;
			if (*format == '%')
				format++;			// skip if %% is found
		}
		format++;
	}
	return (count);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_putnbr(int n)
{
	char c;

	if (n > 0)
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

const char *write_by_mod(va_list *specs_list, const char *format, int count)
{
	char	*specs_str;
	char	specs_char;
	int		specs_val;
	char	modifier;

	format = ft_strchr(format, '%');
	modifier = *(format + 1);
		// get modifier from format
		// function to determine printf based on modifier
		if (modifier == 's')
		{
			specs_str = va_arg(*specs_list, char *);
			ft_putstr(specs_str);
			return (format + 2);
		}
		else if (modifier == 'd')
		{
			specs_val = va_arg(*specs_list, int);
			ft_putnbr(specs_val);
			return (format + 2);
		}
		else if (modifier == '%')
		{
			specs_char = va_arg(*specs_list, int);
			printf("%c", specs_char);
			return (format + 1);
		}
}

void write_string(va_list *specs_list, const char *format, int count)
{
	while (*format)
	{
		if (*format == '%')
		{
			format = write_by_mod(specs_list, format, count);
		}
		write(1, format, 1);
		format++;
		if (!format)
			return ;
	}
}

void ft_printf(const char *format, ...)
{
	va_list	specs_list;
	size_t	specs_count;

	specs_count = specs_count_util(format);
	va_start(specs_list, format);
	write_string(&specs_list, format, specs_count);
	va_end(specs_list);
}

int main(void)
{
	ft_printf("Hello %s, today is %d of April, %d, %%.", "Fero", 30, 2024);

	return (0);
}

static char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}
