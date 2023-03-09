/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:29:45 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:34:07 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
			-rrotate(t_stack **a)
			-ft_rrotate_ab(t_stack **a, t_stack **b)
			-rrotate_a(t_stack **a)
			-rrotate_b(t_stack **b)
			-rrotate_ab(t_stack **a, t_stack **b)
 *rrotate(t_stack **a):
		This function reverse rotates.
		It shifts every element of stack pointed to
		by *a down by one.
		The last element becomes the first element.
		If *a is NULL, or the stack contains one node,
		the function does not do anything.
		*a should point to the beginning of the stack.
 *ft_rrotate_ab(t_stack **a, t_stack **b):
		This function reverse rotates both *a and *b,
		by calling rrotate().
 *rrotate_a(t_stack **a):
 		Calls rrotate(a) and prints message.
 *rrotate_b(t_stack **b):
 		Calls rrotate(b) and prints message.
 *rrotate_ab(t_stack **a, t_stack **b):
 		Calls ft_rrotate_ab(a,b) and prints a message.
 */

void	rrotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a != NULL)
	{
		first = *a;
		if (first->next != NULL)
		{
			last = ft_stacklast(*a);
			last->prev->next = NULL;
			*a = last;
			(*a)->prev = NULL;
			(*a)->next = first;
			first->prev = *a;
			ft_indexing(*a);
		}
	}
}

void	ft_rrotate_ab(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
}

void	rrotate_a(t_stack **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrotate_b(t_stack **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrotate_ab(t_stack **a, t_stack **b)
{
	ft_rrotate_ab(a, b);
	ft_printf("rrr\n");
}
