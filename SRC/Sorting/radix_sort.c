/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:47:30 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:01:02 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

/*This file contains the functions:
				-push_ones(t_stack **a, t_stack **b)
				-push_zeros(t_stack **a, t_stack **b)
				-radix_sort_asc(t_stack **a, t_stack **b)
 * push_ones(t_stack **a, t_stack **b);
		This function pushes all the nodes whose content
		bitwise compared to 1 returns one to stack b.
		If the bitwise comparison returns something else,
		stack a is rotated.
		After every comparison the content is 
		bitshifted by one.
 * push_zeros(t_stack **a, t_stack **b);
		This function pushes all the nodes whose content
		bitwise compared to 1 returns something else then one
	   	to stack b.
		If the bitwise comparison returns one,
		stack a is rotated.
		Everytime the content is bitshifted by one
		after the comparison.
 * radix_sort_asc(t_stack **a, t_stack **b);
		This function iterates thirtytwo times,
		either calling push_zeros() or push_ones().
		This depends on how integers are stored
		in the computer. 
 */

static void	push_ones(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	size_t	size_a;
	size_t	iter;

	node_a = *a;
	size_a = ft_stacksize(*a);
	iter = 0;
	while (iter < size_a)
	{
		if (((node_a->iter_cnt) & 1) == 1)
		{
			(node_a->iter_cnt) = (node_a->iter_cnt) >> 1;
			push_b(a, b);
		}
		else
		{
			(node_a->iter_cnt) = (node_a->iter_cnt) >> 1;
			rotate_a(a);
		}
		node_a = *a;
		iter++;
	}
}

static void	push_zeros(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	size_t	size_a;
	size_t	iter;

	node_a = *a;
	size_a = ft_stacksize(*a);
	iter = 0;
	while (iter < size_a)
	{
		if (((node_a->iter_cnt) & 1) == 1)
		{
			(node_a->iter_cnt) = (node_a->iter_cnt) >> 1;
			rotate_a(a);
		}
		else
		{
			(node_a->iter_cnt) = (node_a->iter_cnt) >> 1;
			push_b(a, b);
		}
		node_a = *a;
		iter++;
	}
}

void	radix_sort_asc(t_stack **a, t_stack **b)
{
	int	iter;

	if (a != NULL)
	{
		if (*a != NULL)
		{
			iter = 1;
			while (iter <= 32)
			{
				if (iter < 32)
				{
					push_zeros(a, b);
					push_a_ntimes(a, b, ft_stacksize(*b) + 1);
					iter++;
				}
				else
				{
					push_ones(a, b);
					push_a_ntimes(a, b, ft_stacksize(*b));
					iter++;
				}
			}
		}
	}
}
