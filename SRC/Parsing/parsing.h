/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:25:37 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 17:46:30 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../Utils/utils.h"
# include "./../types.h"

//FUNCTIONS TO CHECK INPUT ----------
int	check_input_nums(int argc, char *argv[]);
/*This function checks whether the input contains numbers,
  and whether the numbers are integers. 
  The function returns one if the input is correct.
  If the function call ft_split() returns NULL, 
  this function returns -1.
  Otherwise, it returns zero.*/
int	check_doubles(t_stack *stck);
/*This function checks whether the input contains doubles.
  If it contains doubles, it returns zero.
  If it does not contain doubles, it returns one.
  If stck is NULL, it returns -1.*/

//FUNCTIONS TO CONVERT -------------
int	ft_atoi_overflw(const char *str, int *ptr_num);
/*This function conferts the string str to an integer,
  stored in ptr_num. If the string contains an integer bigger
  than INT_MAX or smaller than INT_MIN, the function returns zero
  and the number in ptr_num is not equal to the number in str.*/

#endif
