#! /bin/bash
make re
echo "Tests with three numbers, all permutations"
echo "Input: 1 2 3"
ARG="1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 1 3 2"
ARG="1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 3 2 1"
ARG="3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 2 1 3"
ARG="2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 3 1 2"
ARG="3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 2 3 1"
ARG="2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG

echo "---------------------------------------------------"

echo "Tests with four numbers, some permutations"
echo "Input: 1 2 3 4"
ARG="1 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 4 3 2 1"
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 3 2 1 4"
ARG="3 2 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 1 2 4 3"
ARG="1 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 4 1 2 3"
ARG="4 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG

echo "---------------------------------------------------"

echo "Tests with five numbers, some permutations"
echo "Input: 1 2 3 4 5"
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 5 4 3 2 1"
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 1 2 3 5 4"
ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 5 1 2 3 4"
ARG="5 1 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 4 5 1 2 3"
ARG="4 5 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 1 2 5 3 4"
ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 1 2 5 4 3"
ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo "Input: 3 2 1 4 5"
ARG="3 2 1 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
