/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mstckadd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 14:56:24 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/27 14:58:53 by jhendrik      ########   odam.nl         */
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

void	ft_mstckadd_front(t_mstck **stck, t_mstck *new)
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
			ft_mstck_indexing(*stck);
		}
	}
}

void	ft_mstckadd_back(t_mstck **stck, t_mstck *new)
{
	t_mstck	*last;

	if (stck != NULL)
	{
		if (*stck == NULL)
			*stck = new;
		else
		{
			last = ft_mstcklast(*stck);
			last->next = new;
			new->prev = last;
			new->index = ft_mstcksize(*stck) - 1;
		}
	}
}
