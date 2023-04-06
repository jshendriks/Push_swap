#! /bin/bash
make

# Reset
Reset="\033[0m"			# Text Reset

# Regular Colors
Black="\033[0;30m"			# Black
Red="\033[0;31m"			# Red
Green="\033[0;32m"			# Green
Yellow="\033[0;33m"			# Yellow
Blue="\033[0;34m"			# Blue
Light_Blue="\033[1;34m"		#Light Blue
Purple="\033[0;35m"			# Purple
Cyan="\033[0;36m"			# Cyan
White="\033[0;37m"			# White

# Bold text style
Bold="\033[1m"

echo -e $Cyan "Testing unexpected input" $Reset
echo "Input: nothing"
echo "Output: ..."
./push_swap
echo "Input: empty string "
echo "Output: ..."
./push_swap ""
echo "Input: 1 2 6 5 a"
echo "Output: ..."
./push_swap 1 2 6 5 a
echo "Input: 1 2 4 5 3 1"
echo "Output: ..."
./push_swap 1 2 4 5 3 1
echo "Input: '1 2 3 4' '6 7 5 8'"
echo "Output: ..."
./push_swap "1 2 3 4" "6 7 5 8"
echo "Input: 3 5 1 -2147483649"
echo "Output: ..."
./push_swap 3 5 1 -2147483649
echo "Input: 4 1 5 2147483649"
echo "Output: ..."
./push_swap 4 1 5 2147483649
echo "Input: 1 2 3 4"
echo "Output: ..."
./push_swap 1 2 3 4
