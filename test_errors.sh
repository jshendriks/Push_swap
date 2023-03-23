#! /bin/bash
make re 

echo "Testing unexpected input"
echo "Input: nothing"
./push_swap
echo "Input: empty string "
./push_swap ""
echo "Input: 1 2 6 5 a"
./push_swap 1 2 6 5 a
echo "Input: 1 2 4 5 3 1"
./push_swap 1 2 4 5 3 1
echo "Input: '1 2 3 4' '6 7 5 8'"
./push_swap "1 2 3 4" "6 7 5 8"
echo "Input: 3 5 1 -2147483649"
./push_swap 3 5 1 -2147483649
echo "Input: 4 1 5 2147483649"
./push_swap 4 1 5 2147483649
echo "Input: 1 2 3 4"
./push_swap 1 2 3 4
