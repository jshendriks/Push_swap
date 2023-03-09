/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stackadd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:03:31 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:05:32 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

/*This file contains the functions:
			-ft_stackadd_front(t_stack **stck, t_stack *new)
			-ft_stackadd_back(t_stack **stck, t_stack *new)
 *ft_stackadd_front(t_stack **stck, t_stack *new):
  		This function adds the node new to the front of the 
		stack stck. 
		If stck is NULL, stck becomes the new node.
		stck should point to the beginning of the stack.
 *ft_stackadd_back(t_stack **stck, t_stack *new):
  		This function adds the node new to the back of stck.
		The last node is determined by calling the function 
		ft_stacklast(). 
		If stck is NULL, stck becomes the new node.
 */

void	ft_stackadd_front(t_stack **stck, t_stack *new)
{
	if (stck != NULL)
	{
		if (*stck == NULL)
			*stck = new;
		else if (new != NULL)
		{
			new->next = *stck;
			(*stck)->prev = new;
			*stck = new;
			ft_indexing(*stck);
		}
	}
}

void	ft_stackadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*last;

	if (stck != NULL)
	{
		if (*stck == NULL)
			*stck = new;
		else
		{
			last = ft_stacklast(*stck);
			last->next = new;
			new->prev = last;
			new->index = ft_stacksize(*stck) - 1;
		}
	}
}
