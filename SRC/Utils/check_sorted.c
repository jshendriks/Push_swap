/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:30:39 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 09:46:45 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "./../src.h"

/*This file contains the functions:
   			-issorted_asc(t_stack *a)
			-issorted_des(t_stack *a)
 * issorted_asc(t_stack *a)
		This function checks whether the given 
		stack a is sorted in ascending order
		by iterating through the stack. 
		If a is NULL, it returns -2.
		If a is not sorted in ascending order,
		it returns zero.
		Otherwise, it returns -1.
 * issorted_des(t_stack *a) 		CHANGED CODE BUT COMMENT NOT UPDATED!!!
		This function checks whether the given
		stack a is sorted in descending order
		by iterating through the stack.
		If a is NULL, it returns -2.
		If a is not sorted in descending order,
		it returns zero.
		Otherwise, it returns -1.
 */

int	issorted_asc(t_stack *a)
{
	t_stack	*node;

	node = a;
	if (a == NULL)
		return (-2);
	while (node != NULL && node->next != NULL)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (-1);
}

int	issorted_des(t_stack *a)
{
	t_stack	*node;

	node = a;
	if (a == NULL)
		return (-2);
	while (node != NULL && node->next != NULL)
	{
		if (node->content < node->next->content)
			return (0);
		node = node->next;
	}
	return (-1);
}
