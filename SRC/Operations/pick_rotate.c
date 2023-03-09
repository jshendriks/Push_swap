/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pick_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:28:01 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 15:01:06 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
				-ft_pickrotate_a(t_stack **a, size_t n, size_t size)
				-ft_pickrotate_b(t_stack **a, size_t n, size_t size)
				-pick_rotate(t_stack **a, size_t n, int c)
 * ft_pickrotate_a(t_stack **a, size_t n, size_t size):
		This function determines whether it is 
		more efficient to rotate or reverse rotate.
		It assumes the given stack is stack a.
 * ft_pickrotate_b(t_stack **a, size_t n, size_t size):
		This function determines whether it is
		more efficient to rotate or reverse rotate.
		It assumes the given stack is stack b.
 * pick_rotate(t_stack **a, size_t n, int c):
		This function determines whether it is more useful
		to use rotate, or reverse rotate, depending on
		how many rotations (n times) are expected
		and the size of the stack.
 */

static void	ft_pickrotate_a(t_stack **a, size_t n, size_t size)
{
	if (n < (size / 2))
		rotate_a_ntimes(a, n);
	else
		rrotate_a_ntimes(a, size - n);
}

static void	ft_pickrotate_b(t_stack **a, size_t n, size_t size)
{
	if (n < (size / 2))
		rotate_b_ntimes(a, n);
	else
		rrotate_b_ntimes(a, size - n);
}

void	pick_rotate(t_stack **a, size_t n, int c)
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
					ft_pickrotate_a(a, n, size);
				else
					ft_pickrotate_b(a, n, size);
			}
		}
	}
}
