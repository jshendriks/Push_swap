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

echo -e $Cyan "Tests with three numbers, all permutations" $Reset
echo "Input: 1 2 3"
TEMP_VAR="$(ARG="1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 1 3 2"
TEMP_VAR="$(ARG="1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 3 2 1"
TEMP_VAR="$(ARG="3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 2 1 3"
TEMP_VAR="$(ARG="2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 3 1 2"
TEMP_VAR="$(ARG="3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 2 3 1"
TEMP_VAR="$(ARG="2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset

echo "---------------------------------------------------"

echo -e $Cyan "Tests with four numbers, some permutations" $Reset
echo "Input: 1 2 3 4"
TEMP_VAR="$(ARG="1 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 4 3 2 1"
TEMP_VAR="$(ARG="4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 3 2 1 4"
TEMP_VAR="$(ARG="3 2 1 4"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 1 2 4 3"
TEMP_VAR="$(ARG="1 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 4 1 2 3"
TEMP_VAR="$(ARG="4 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset

echo "---------------------------------------------------"

echo -e $Cyan "Tests with five numbers, some permutations" $Reset
echo "Input: 1 2 3 4 5"
TEMP_VAR="$(ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 5 4 3 2 1"
TEMP_VAR="$(ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 1 2 3 5 4"
TEMP_VAR="$(ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 5 1 2 3 4"
TEMP_VAR="$(ARG="5 1 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 4 5 1 2 3"
TEMP_VAR="$(ARG="4 5 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 1 2 5 3 4"
TEMP_VAR="$(ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 1 2 5 4 3"
TEMP_VAR="$(ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
echo "Input: 3 2 1 4 5"
TEMP_VAR="$(ARG="3 2 1 4 5"; ./push_swap $ARG | ./checker_Mac $ARG)"
echo -e $Green $TEMP_VAR $Reset
