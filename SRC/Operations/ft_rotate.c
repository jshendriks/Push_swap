/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:24:26 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 14:38:57 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
			-rotate(t_stack **a)
			-ft_rotate_ab(t_stack **a, t_stack **b)
			-rotate_a(t_stack **a)
			-rotate_b(t_stack **b)
			-rotate_ab(t_stack **a, t_stack **b)
 *rotate(t_stack **a):
		This function shifts every element of stack 
		pointed to by *a up by one.
		The first element becomes the last element.
		If *a is NULL, or the stack contains one node,
		the function does not do anything.
		*a should point to the beginning of the stack.
 *ft_rotate_ab(t_stack **a, t_stack **b):
		This function shifts every element of the stacks
		pointed to by *a and *b up by one, 
		by calling the function rotate().
 *rotate_a(t_stack **a):
		Calls rotate(a) and prints message.
 *rotate_b(t_stack **b):
 		Calls rotate(b) and prints message.
 *rotate_ab(t_stack **a, t_stack **b):
 		Calls ft_rotate_ab(a,b) and prints message.
 */

static void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a != NULL)
	{
		first = *a;
		if (first->next != NULL)
		{
			last = ft_stacklast(*a);
			*a = first->next;
			(*a)->prev = NULL;
			last->next = first;
			first->prev = last;
			first->next = NULL;
			ft_indexing(*a);
		}
	}
}

static void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	ft_rotate_ab(a, b);
	ft_printf("rr\n");
}
