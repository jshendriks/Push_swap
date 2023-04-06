/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_doubles.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:21:41 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 12:10:25 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

/*This file contains the function check_doubles(t_stack *stck)
 * check_doubles(t_stack *stck):
		This function checks whether the given stack stck contains
		doubles by iterating through the stack.
		When no doubles are found, the function returns one.
		If doubles are found, the function returns zero.
		If the given stck is NULL, the function returns -1.
 */

int	check_doubles(t_stack *stck)
{
	t_stack	*node1;
	t_stack	*node2;

	if (stck != NULL)
	{
		node1 = stck;
		while (node1)
		{
			node2 = node1->next;
			while (node2)
			{
				if ((node1->content) == (node2->content))
					return (0);
				node2 = node2->next;
			}
			node1 = node1->next;
		}
		return (1);
	}
	return (-1);
}
