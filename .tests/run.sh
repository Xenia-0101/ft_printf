#!/bin/bash

rm -f ../libftprintf.a
rm -f ../ft_printf.o
clear

cd ../
make all
# make clean

cd tests/
# clear

cc -g ../ft_printf.c ../libft/libft.a main.c test_printf.c
./a.out
