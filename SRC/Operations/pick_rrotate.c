/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pick_rrotate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:45:11 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 15:02:07 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
				-ft_pickrrotate_a(t_stack **a, size_t n, size_t size)
				-ft_pickrrotate_b(t_stack **a, size_t n, size_t size)
				-pick_rrotate(t_stack **a, size_t n, int c)
 *ft_pickrrotate_a(t_stack **a, size_t n, size_t size):
 		This function determines whether it is
		more efficient to rotate or reverse rotate.
		It assumes the given stack is stack a.
 *ft_pickrrotate_b(t_stack **a, size_t n, size_t size):
 		This function determines whether it is 
		more efficient to rotate or reverse rotate.
		It assumes the given stack is stack b.
 *pick_rrotate(t_stack **a, size_t n, int c):
 		This function determines whether it is 
		more efficient to use reverse rotate or rotate,
		depending on how many reverse rotations (n times)
		are expected and the size of the given stack.
 */

static void	ft_pickrrotate_a(t_stack **a, size_t n, size_t size)
{
	if (n < (size / 2))
		rrotate_a_ntimes(a, n);
	else
		rotate_a_ntimes(a, size - n);
}

static void	ft_pickrrotate_b(t_stack **a, size_t n, size_t size)
{	
	if (n < (size / 2))
		rrotate_b_ntimes(a, n);
	else
		rotate_b_ntimes(a, size - n);
}

void	pick_rrotate(t_stack **a, size_t n, int c)
{
	size_t	size;

	if (a != NULL)
	{
		if (*a != NULL)
		{
			size = ft_stacksize(*a);
			if (n > 0 && n <= size)
			{
				if (c == 'a')
					ft_pickrrotate_a(a, n, size);
				else
					ft_pickrrotate_b(a, n, size);
			}
		}
	}
}
