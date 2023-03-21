/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_ntimes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:18:44 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 11:05:10 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
				-push_a_ntimes(t_stack **a, t_stack **b, size_t n)
				-push_b_ntimes(t_stack **a, t_stack **b, size_t n)
 *push_a_ntimes(t_stack **a, t_stack **b, size_t n):
 		This function calls push_a() n times.
 *push_b_ntimes(t_stack **a, t_stack **b, size_t n):
 		This function calls push_b() n times.
 */

void	push_a_ntimes(t_stack **a, t_stack **b, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			push_a(a, b);
			i++;
		}
	}
}

void	push_b_ntimes(t_stack **a, t_stack **b, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			push_b(a, b);
			i++;
		}
	}
}
