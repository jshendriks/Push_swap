/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_ntimes_mstck.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:32:20 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 14:33:39 by jhendrik      ########   odam.nl         */
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

void	push_a_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			push_a_mstck(a, b);
			i++;
		}
	}
}

void	push_b_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			push_b_mstck(a, b);
			i++;
		}
	}
}
