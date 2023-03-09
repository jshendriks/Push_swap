/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexswap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:22:05 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 14:26:24 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
					-indexswap_a(t_stack **a, size_t n, size_t size)
					-indexswap_b(t_stack **b, size_t n, size_t size)
 *indexswap_a(t_stack **a, size_t n, size_t size):
			This function swaps the element with 
			index n with the next element in stack a.
 *indexswap_b(t_stack **b, size_t n, size_t size):
 			This function swaps the element with
			index n with the next element in stack b.
 */

void	indexswap_a(t_stack **a, size_t n, size_t size)
{
	size_t	r;

	if (n <= (size / 2))
	{
		rotate_a_ntimes(a, n);
		swap_a(a);
		rrotate_a_ntimes(a, n);
	}
	else
	{
		r = size - n;
		rrotate_a_ntimes(a, r);
		swap_a(a);
		rotate_a_ntimes(a, r);
	}
}

void	indexswap_b(t_stack **b, size_t n, size_t size)
{
	size_t	r;

	if (n <= (size / 2))
	{
		rotate_b_ntimes(b, n);
		swap_b(b);
		rrotate_b_ntimes(b, n);
	}
	else
	{
		r = size - n;
		rrotate_b_ntimes(b, r);
		swap_b(b);
		rotate_b_ntimes(b, r);
	}
}
