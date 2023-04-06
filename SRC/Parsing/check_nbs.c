/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_nbs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:18:09 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 12:02:31 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

/*This file contains the functions:
			-check_strnum(char *str)
			-check_input(int argc, char *argv[])
			-check_strmm(char *str)
	*check_strnum(char *str):
		This function checks whether the string pointed to by str,
		only contains digits or a -/+ at the beginning
		of the string by iterating through str.
		If the string only contains these characters the function
		returns one.
		Otherwise, the function returns zero.
		If str is NULL, the function returns zero.
	*check_input_nums(int argc, char *argv[]):
		This function checks whether the input given is correct.
		This means that there are 2 or more input arguments,
		and if the input are strings only containing digits and
		+/- at the beginning of the string.
		If the input is incorrect, the function returns zero.
		If the function ft_split() returns NULL, the function returns -1.
		Otherwise, the function returns one.
		If one of the arguments is NULL-pointer, the function returns zero.
	*check_strmm(char *str):
		This function calls the function ft_atoi_overflw() to check
		whether the input is an integer bigger or smaller than INT_MAX
		or INT_MIN.
		If the number is bigger or smaller than INT_MAX or INT_MIN,
		it returns zero.
		Otherwise, it returns one.
	*/

static int	check_strnum(char *str)
{
	char	*temp;

	temp = str;
	if (str != NULL)
	{
		if (ft_isdigit(*str) != 1)
		{
			if (*str != '-' && *str != '+')
				return (0);
		}
		if (*str == '-' || *str == '+')
			temp++;
		while (*temp)
		{
			if (ft_isdigit(*temp) != 1)
				return (0);
			temp++;
		}
		return (1);
	}
	return (0);
}

static int	check_strmm(char *str)
{
	int	nb;
	int	*ptr_nb;

	nb = 0;
	ptr_nb = &nb;
	return (ft_atoi_overflw((const char *)str, ptr_nb));
}

int	check_input_nums(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**ptr;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		j = 0;
		ptr = ft_split((const char *)argv[i], ' ');
		if (ptr == NULL)
			return (-1);
		while (ptr[j] != NULL)
		{
			if (check_strnum(ptr[j]) == 0 || check_strmm(ptr[j]) == 0)
				return (0);
			j++;
		}
		ft_free_double(ptr);
		i++;
	}
	return (1);
}
