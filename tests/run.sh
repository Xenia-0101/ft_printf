#!/bin/bash

rm -f ../libftprintf.a
rm -f ../ft_printf.o
clear

cd ../
make all
# make clean

cd tests/
# clear

cc -g main.c ../ft_printf.c ../libft/libft.a
./a.out
