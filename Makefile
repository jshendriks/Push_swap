# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhendrik <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 18:24:29 by jhendrik      #+#    #+#                  #
#    Updated: 2023/03/23 09:49:09 by jhendrik      ########   odam.nl          #
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
			./SRC/main.c

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
