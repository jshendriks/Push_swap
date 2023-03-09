/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_makestack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 15:04:41 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 15:22:28 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

/*This file contains the functions:
				-add_split(char **split, t_stack **stck)
				-ft_makestack_int(int argc, char *argv[])
 * add_split(char **split, t_stack **stck):
		This function adds the elements in split
		to the stack stck, by iterating through
		split and converting every element to an
		integer and making a node of it.
		This function returns stck,
		or NULL if an error occured.
 * ft_makestack_int(int argc, char *argv[]):
		This function makes a stack with the given input.
		It assumes the input has been checked and is correct.
		It returns the stack, or NULL if an error occured.
 */

static t_stack	*add_split(char **split, t_stack **stck)
{
	t_stack	*node;
	int		j;

	j = 0;
	while (split[j] != NULL)
	{
		node = ft_stacknew(ft_atoi((const char *)split[j]));
		if (node == NULL)
		{
			ft_stackclear(stck);
			ft_free_double(split);
			return (NULL);
		}
		ft_stackadd_back(stck, node);
		j++;
	}
	return (*stck);
}

t_stack	*ft_makestack_int(int argc, char *argv[])
{
	t_stack	*stck;
	t_stack	*node;
	char	**split;
	int		i;

	i = 1;
	stck = NULL;
	while (i < argc)
	{
		split = ft_split((char const *)argv[i], ' ');
		if (split != NULL)
		{
			node = add_split(split, &stck);
			if (node == NULL)
				return (NULL);
			ft_free_double(split);
			i++;
		}
		else
		{
			ft_stackclear(&stck);
			return (NULL);
		}
	}
	return (stck);
}
