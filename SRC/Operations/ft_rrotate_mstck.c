/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrotate_mstck.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:41:40 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 14:44:51 by jhendrik      ########   odam.nl         */
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

static void	rrotate(t_mstck **a)
{
	t_mstck	*first;
	t_mstck	*last;

	if (*a != NULL)
	{
		first = *a;
		if (first->next != NULL)
		{
			last = ft_mstcklast(*a);
			last->prev->next = NULL;
			*a = last;
			(*a)->prev = NULL;
			(*a)->next = first;
			first->prev = *a;
			ft_mstck_indexing(*a);
		}
	}
}

static void	ft_rrotate_ab(t_mstck **a, t_mstck **b)
{
	rrotate(a);
	rrotate(b);
}

void	rrotate_a_mstck(t_mstck **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrotate_b_mstck(t_mstck **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrotate_ab_mstck(t_mstck **a, t_mstck **b)
{
	ft_rrotate_ab(a, b);
	ft_printf("rrr\n");
}
