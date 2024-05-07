#!/bin/bash

rm -f libftprintf.a
clear

make all
make clean

clear

# run the app with command line argument
./libftprintf.a
