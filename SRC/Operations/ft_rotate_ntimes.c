/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate_ntimes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:47:43 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:52:37 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
			-rotate_a_ntimes(t_stack **a, size_t n)
			-rotate_b_ntimes(t_stack **b, size_t n)
			-rrotate_a_ntimes(t_stack **a, size_t n)
			-rrotate_b_ntimes(t_stack **b, size_t n)
 *rotate_a_ntimes(t_stack **a, size_t n):
 	Calls the function rotate_a(a), n times.
 *rotate_b_ntimes(t_stack **b, size_t n):
 	Calls the function rotate_b(b), n times.
 *rrotate_a_ntimes(t_stack **a, size_t n):
 	Calls the function rrotate_a(a), n times.
 *rrotate_b_ntimes(t_stack **b, size_t n):
	Calls the function rrotate_b(b), n times.
 */

void	rotate_a_ntimes(t_stack **a, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rotate_a(a);
			i++;
		}
	}
}

void	rotate_b_ntimes(t_stack **b, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rotate_b(b);
			i++;
		}
	}
}

void	rrotate_a_ntimes(t_stack **a, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rrotate_a(a);
			i++;
		}
	}
}

void	rrotate_b_ntimes(t_stack **b, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rrotate_b(b);
			i++;
		}
	}
}
