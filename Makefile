# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhendrik <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 18:24:29 by jhendrik      #+#    #+#                  #
#    Updated: 2023/04/03 17:29:48 by jhendrik      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
HEADER := ./SRC/src.h
LIBS_HEADER := ./libft/libft.h
LIBS := ./libft/libft.a
SRCFILES := ./SRC/Sorting/insertionsort.c		\
			./SRC/Sorting/radix_sort.c			\
			./SRC/Sorting/reverse_order.c		\
			./SRC/Sorting/ft_smallsort.c		\
			./SRC/Sorting/smallsort_nb.c		\
			./SRC/Sorting/ft_small_two.c		\
			./SRC/Sorting/ft_small_three.c		\
			./SRC/Sorting/quirky_sort.c			\
			./SRC/Operations/ft_push_ntimes.c	\
			./SRC/Operations/ft_push.c			\
			./SRC/Operations/ft_rotate_ntimes.c	\
			./SRC/Operations/ft_rotate.c		\
			./SRC/Operations/ft_rrotate.c		\
			./SRC/Operations/ft_swap.c			\
			./SRC/Operations/indexswap.c		\
			./SRC/Operations/pick_rotate.c		\
			./SRC/Operations/pick_rrotate.c		\
			./SRC/Operations/swap.c				\
			./SRC/Operations/ft_push_mstck.c	\
			./SRC/Operations/ft_push_ntimes_mstck.c	\
			./SRC/Operations/ft_rotate_mstck.c	\
			./SRC/Operations/ft_rotate_ntimes_mstck.c	\
			./SRC/Operations/ft_rrotate_mstck.c	\
			./SRC/Operations/ft_rrr_ntimes_mstck.c	\
			./SRC/Operations/ft_swap_mstck.c	\
			./SRC/Operations/swap_mstck.c		\
			./SRC/Parsing/ft_overflow.c			\
			./SRC/Parsing/check_doubles.c		\
			./SRC/Parsing/check_nbs.c			\
			./SRC/Utils/check_sorted.c			\
			./SRC/Utils/ft_free_xtr.c			\
			./SRC/Utils/ft_makestack.c			\
			./SRC/Utils/ft_stackadd.c			\
			./SRC/Utils/ft_stackdel.c			\
			./SRC/Utils/ft_stackother.c			\
			./SRC/Utils/ft_mm.c					\
			./SRC/Utils/ft_merge.c				\
			./SRC/Utils/ft_makemstck.c			\
			./SRC/Utils/ft_mstckadd.c			\
			./SRC/Utils/ft_mstckdel.c			\
			./SRC/Utils/ft_mstcknew.c			\
			./SRC/Utils/ft_mstckother.c			\
			./SRC/Utils/ft_place.c				\
			./SRC/Utils/calcmoves_down.c		\
			./SRC/Utils/exec_best.c				\
			./SRC/Utils/ft_calcmoves.c			\
			./SRC/Utils/ft_moves.c				\
			./SRC/main_test.c

OBJFILES := $(SRCFILES:.c=.o)
CFLAGS ?= -Wall -Werror -Wextra

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

all: $(NAME)

$(NAME): $(OBJFILES)
	@echo $(Light_Blue) Compiling $(NAME) $(Reset)
	@$(MAKE) bonus -C libft
	@$(CC) $(LIBS) $(OBJFILES) -o $(NAME)
	@echo $(Green) Succesfully made program $(NAME) $(Reset)

%.o: %.c $(HEADER)
	@$(CC) -c $(CFLAGS) -o $@ $< 

clean:
	@echo $(Yellow) Cleaning $(NAME) $(Reset)
	@rm -f $(OBJFILES)
	@$(MAKE) -C libft clean

fclean: clean
	@echo $(Yellow) Thorough cleaning $(NAME) $(Reset)
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
