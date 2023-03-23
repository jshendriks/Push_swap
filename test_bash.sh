#! /bin/bash
make re
echo "Tests with three numbers, all permutations"
echo "Input: 1 2 3"
./push_swap 1 2 3 | wc -l
echo "Input: 1 3 2"
./push_swap 1 3 2 | wc -l
echo "Input: 3 2 1"
./push_swap 3 2 1 | wc -l
echo "Input: 2 1 3"
./push_swap 2 1 3 | wc -l
echo "Input: 3 1 2"
./push_swap 3 1 2 | wc -l
echo "Input: 2 3 1"
./push_swap 2 3 1 | wc -l

echo "---------------------------------------------------"

echo "Tests with four numbers, some permutations"
echo "Input: 1 2 3 4"
./push_swap 1 2 3 4 | wc -l
echo "Input: 4 3 2 1"
./push_swap 4 3 2 1 | wc -l
echo "Input: 3 2 1 4"
./push_swap 3 2 1 4 | wc -l
echo "Input: 1 2 4 3"
./push_swap 1 2 4 3 | wc -l
echo "Input: 4 1 2 3"
./push_swap 4 1 2 3 | wc -l

echo "---------------------------------------------------"

echo "Tests with five numbers, some permutations"
echo "Input: 1 2 3 4 5"
./push_swap 1 2 3 4 5 | wc -l
echo "Input: 5 4 3 2 1"
./push_swap 5 4 3 2 1 | wc -l
echo "Input: 1 2 3 5 4"
./push_swap 1 2 3 5 4 | wc -l
echo "Input: 5 1 2 3 4"
./push_swap 5 1 2 3 4 | wc -l
echo "Input: 4 5 1 2 3"
./push_swap 4 5 1 2 3 | wc -l
echo "Input: 1 2 5 3 4"
./push_swap 1 2 5 3 4 | wc -l
echo "Input: 1 2 5 4 3"
./push_swap 1 2 5 4 3 | wc -l
echo "Input: 3 2 1 4 5"
./push_swap 3 2 1 4 5 | wc -l

