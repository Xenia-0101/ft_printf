#!/bin/bash

rm -f ../libftprintf.a
rm -f ../ft_printf.o
clear

cd ../
make all

cd tests/
# clear

cc -g main.c ../ft_printf.o ../libft/libft.a
./a.out
