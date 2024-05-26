/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:51:08 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/28 10:51:08 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void ft_printf(char *string, ...);

/* void var_function(int n, ...)
{
	char **str;
	va_list to_print;

	va_start(to_print, n);
	printf("%d\n", n);
	str = va_arg(to_print, char **);
	while (n > 0)
	{
		printf("%s\n", str[--n]);
	}
	va_end(to_print);
} */

void test_printf(void)
{
	printf("\n");
	int val = -4095;
	int hex_val = 0xfff;
/*
	ft_printf("\nTesting i\n");

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15i | %15i |\n", "%i", val, hex_val);
	printf("| %-10s | %-15i | %-15i |\n", "%-i", val, hex_val);
	printf("| %-10s | %015i | %015i |\n", "%0i", val, hex_val);
	printf("| %-10s | %15.i | %15.i |\n", "%.i", val, hex_val);
	printf("| %-10s | %15.4i | %15.4i |\n", "%.4i", val, hex_val);
	printf("| %-10s | %15.8i | %15.8i |\n", "%.8i", val, hex_val);
	printf("| %-10s | %-15.8i | %-15.8i |\n", "%-.8i", val, hex_val);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15i | %15i |\n", "%i", val, hex_val);
	ft_printf("| %-10s | %-15i | %-15i |\n", "%-i", val, hex_val);
	ft_printf("| %-10s | %015i | %015i |\n", "%0i", val, hex_val);
	ft_printf("| %-10s | %15.i | %15.i |\n", "%.i", val, hex_val);
	ft_printf("| %-10s | %15.4i | %15.4i |\n", "%.4i", val, hex_val);
	ft_printf("| %-10s | %15.8i | %15.8i |\n", "%.8i", val, hex_val);
	ft_printf("| %-10s | %-15.8i | %-15.8i |\n", "%-.8i", val, hex_val);
	ft_printf("|------------|-----------------|-----------------|\n");

	// 0 ignored with precision (.) and %i format
	// 0 ignored with (-) flag

	printf("\n");
	ft_printf("\nTesting d\n");

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15d | %15d |\n", "%d", val, hex_val);
	printf("| %-10s | %-15d | %-15d |\n", "%-d", val, hex_val);
	printf("| %-10s | %015d | %015d |\n", "%0d", val, hex_val);
	printf("| %-10s | %15.d | %15.d |\n", "%.d", val, hex_val);
	printf("| %-10s | %15.4d | %15.4d |\n", "%.4d", val, hex_val);
	printf("| %-10s | %15.8d | %15.8d |\n", "%.8d", val, hex_val);
	printf("| %-10s | %-15.8d | %-15.8d |\n", "%-.8d", val, hex_val);
	printf("| %-10s | %15.19d | %15.19d |\n", "%.19d", val, hex_val);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "int 3456", "int 0xfff");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15d | %15d |\n", "%d", val, hex_val);
	ft_printf("| %-10s | %-15d | %-15d |\n", "%-d", val, hex_val);
	ft_printf("| %-10s | %015d | %015d |\n", "%0d", val, hex_val);
	ft_printf("| %-10s | %15.d | %15.d |\n", "%.d", val, hex_val);
	ft_printf("| %-10s | %15.4d | %15.4d |\n", "%.4d", val, hex_val);
	ft_printf("| %-10s | %15.8d | %15.8d |\n", "%.8d", val, hex_val);
	ft_printf("| %-10s | %-15.8d | %-15.8d |\n", "%-.8d", val, hex_val);
	ft_printf("| %-10s | %15.19d | %15.19d |\n", "%.19d", val, hex_val);
	ft_printf("|------------|-----------------|-----------------|\n");

	ft_printf("\n"); */
/* 	ft_printf("\nTesting s\n");

	char greet[] = "Hey >:-)";
	printf("|------------|-----------------|\n");
	printf("| %-10s | %-15s |\n", "Input", "char[] Hey >:-)");
	printf("|............|.................|\n");
	printf("| %-10s | %15s |\n", "Format", "Print");
	printf("|------------|-----------------|\n");
	printf("| %-10s | %s |\n", "%s", greet);
	printf("| %-10s | %5s |\n", "%5s", greet);
	printf("| %-10s | %5.2s |\n", "%5.2s", greet);
	printf("| %-10s | %8s |\n", "%8s", greet);
	printf("| %-10s | %15s |\n", "%15s", greet);
	printf("| %-10s | %-15s |\n", "%-15s", greet);
	printf("|------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|\n");
	ft_printf("| %-10s | %-15s |\n", "Input", "char[] Hey >:-)");
	ft_printf("|............|.................|\n");
	ft_printf("| %-10s | %15s |\n", "Format", "Print");
	ft_printf("|------------|-----------------|\n");
	ft_printf("| %-10s | %s |\n", "%s", greet);
	ft_printf("| %-10s | %5s |\n", "%5s", greet);
	ft_printf("| %-10s | %5.2s |\n", "%5.2s", greet);
	ft_printf("| %-10s | %8s |\n", "%8s", greet);
	ft_printf("| %-10s | %15s |\n", "%15s", greet);
	ft_printf("| %-10s | %-15s |\n", "%-15s", greet);
	ft_printf("|------------|-----------------|\n");
	// '0' flag used with ‘%s’

	printf("\n"); */
	ft_printf("\nTesting u\n");

	unsigned int u_int = 20;
	unsigned int u_int_n = -20;
	char c = 'c';
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-46s |\n", "Testing %u specifier.");
	printf("|............|.................|.................|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15u |\n", "%15u", "20", u_int);
	printf("| %-10s | %15s | %15u |\n", "%15u", "-20", u_int_n);
	printf("| %-10s | %15s | %-15u |\n", "%-15u", "20", u_int);
	printf("| %-10s | %15s | %-15u |\n", "%-15u", "-20", u_int_n);
	printf("| %-10s | %15s | %15u |\n", "%15u", "char c", c);
	printf("| %-10s | %15s | %015u |\n", "%015u", "char c", c);
	printf("| %-10s | %15s | %15u |\n", "%15u", "int 0xfff", hex_val);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-46s |\n", "Testing %u specifier.");
	ft_printf("|............|.................|.................|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15u |\n", "%15u", "20", u_int);
	ft_printf("| %-10s | %15s | %15u |\n", "%15u", "-20", u_int_n);
	ft_printf("| %-10s | %15s | %-15u |\n", "%-15u", "20", u_int);
	ft_printf("| %-10s | %15s | %-15u |\n", "%-15u", "-20", u_int_n);
	ft_printf("| %-10s | %15s | %15u |\n", "%15u", "char c", c);
	ft_printf("| %-10s | %15s | %015u |\n", "%015u", "char c", c);
	ft_printf("| %-10s | %15s | %15u |\n", "%15u", "int 0xfff", hex_val);
	ft_printf("|------------|-----------------|-----------------|\n");

	printf("\n");
	ft_printf("\nTesting x, X\n");


	int hex_num = 0xffffff;
	int dec_num = 42;
	int dec_num_n = -42;
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-46s |\n", "Testing %x and %X specifier.");
	printf("|............|.................|.................|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15x |\n", "%15x", "0xffffff", hex_num);
	printf("| %-10s | %15s | %-15X |\n", "%-15X", "0xffffff", hex_num);
	printf("| %-10s | %15s | %15x |\n", "%15x", "42", dec_num);
	printf("| %-10s | %15s | %-15X |\n", "%-15X", "42", dec_num);
	printf("| %-10s | %15s | %15x |\n", "%15x", "-42", dec_num_n);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-46s |\n", "Testing %x and %X specifier.");
	ft_printf("|............|.................|.................|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15x |\n", "%15x", "0xffffff", hex_num);
	ft_printf("| %-10s | %15s | %-15X |\n", "%-15X", "0xffffff", hex_num);
	ft_printf("| %-10s | %15s | %15x |\n", "%15x", "42", dec_num);
	ft_printf("| %-10s | %15s | %-15X |\n", "%-15X", "42", dec_num);
	ft_printf("| %-10s | %15s | %15x |\n", "%15x", "-42", dec_num_n);
	ft_printf("|------------|-----------------|-----------------|\n");

	// incorrect result for negative number

	printf("\n");

	char p = 'r';
	char *pp = &p;
	ft_printf("\nTesting p\n");

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-46s |\n", "Testing %p specifier.");
	printf("|............|.................|.................|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15p |\n", "%15p", "&(char p)", &p);
	printf("| %-10s | %15s | %15p |\n", "%15p", "&(char *pp)", &pp);
	printf("| %-10s | %15s | %15p |\n", "%15p", "char *pp", pp);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-46s |\n", "Testing %p specifier.");
	ft_printf("|............|.................|.................|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15p |\n", "%15p", "&(char p)", &p);
	ft_printf("| %-10s | %15s | %15p |\n", "%15p", "&(char *pp)", &pp);
	ft_printf("| %-10s | %15s | %15p |\n", "%15p", "char *pp", pp);
	ft_printf("|------------|-----------------|-----------------|\n");

	printf("\n");

	ft_printf("\nTesting c\n");
	char c_1 = 'r';
	char *c_2 = "hell";
	int c_3 = 97;
	int c_4 = 255;

	printf("|------------|-----------------|-----------------|\n");
	printf("| %-46s |\n", "Testing %c specifier.");
	printf("|............|.................|.................|\n");
	printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	printf("|------------|-----------------|-----------------|\n");
	printf("| %-10s | %15s | %15c |\n", "%15c", "char c = r", c_1);
	printf("| %-9s | %15s | %14c |\n", "%15c", "&(char *c = hell)", *c_2);
	printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 97", c_3);
	printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 255", c_4);
	printf("|------------|-----------------|-----------------|\n");

	ft_printf("\nft_printf\n");

	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-46s |\n", "Testing %c specifier.");
	ft_printf("|............|.................|.................|\n");
	ft_printf("| %-10s | %15s | %15s |\n", "Format", "Input", "Print");
	ft_printf("|------------|-----------------|-----------------|\n");
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "char c = r", c_1);
	ft_printf("| %-9s | %15s | %14c |\n", "%15c", "&(char *c = hell)", *c_2);
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 97", c_3);
	ft_printf("| %-10s | %15s | %15c |\n", "%15c", "int x = 255", c_4);
	ft_printf("|------------|-----------------|-----------------|\n");
}
