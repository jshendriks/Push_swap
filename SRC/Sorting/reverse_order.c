/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_order.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:42:34 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 11:46:56 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

/*This file contains the functions:
				-reverse_order_a(t_stack **a, t_stack **b)
				-reverse_order_b(t_stack **a, t_stack **b)
 * reverse_order_a(t_stack **a, t_stack **b);
		This function reverses the order of elements in stack a.
		It only does this correctly if stack b is empty (*b = NULL).
 * reverse_order_b(t_stack **a, t_stack **b);
		This function reverses the order of elements in stack b.
		It only does this correctly if stack a is empty (*a = NULL).
 */

void	reverse_order_a(t_stack **a, t_stack **b)
{
	push_b_ntimes(a, b, ft_stacksize(*a));
	while (*b != NULL)
	{
		if ((*b)->next != NULL)
			rrotate_b(b);
		push_a(a, b);
	}
}

void	reverse_order_b(t_stack **a, t_stack **b)
{
	push_a_ntimes(a, b, ft_stacksize(*b));
	while (*a != NULL)
	{
		if ((*a)->next != NULL)
			rrotate_a(a);
		push_b(a, b);
	}
}
