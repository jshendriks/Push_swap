/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mstckother.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 14:45:52 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/27 14:49:24 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

/*This file contains the functions:
			-ft_stacklast(t_stack *stck)
			-ft_stackfirst(t_stack *stck)
			-ft_stacksize(t_stack *stck)
			-ft_indexing(t_stack *stck)
  *ft_stacklast(t_stack *stck):
  		This function locates the last node in stck 
		by iterating through stack.
		It returns the last node.
		If stck is NULL, it returns NULL.
  *ft_stackfirst(t_stack *stck):
  		This function locates the first node in stck
		by iterating through stack.
		It returns the first node.
		If stck is NULL, it returns NULL.
  *ft_stacksize(t_stack *stck):
  		This function iterates through the stack,
		counting the amount of nodes, 
		and returns this number.
		If the stack is bigger than
		MAX size of size_t, overflow will occur.
  *ft_indexing(t_stack *stck):
  		This function re-indexes the given stack.
  */

t_mstck	*ft_mstcklast(t_mstck *stck)
{
	t_mstck	*cur;
	t_mstck	*prv;

	if (stck == NULL)
		return (stck);
	cur = stck;
	prv = NULL;
	while (cur != NULL)
	{
		prv = cur;
		cur = cur->next;
	}
	return (prv);
}

t_mstck	*ft_mstckfirst(t_mstck *stck)
{
	t_mstck	*cur;
	t_mstck	*prv;

	if (stck == NULL)
		return (stck);
	cur = stck;
	prv = NULL;
	while (cur != NULL)
	{
		prv = cur;
		cur = cur->prev;
	}
	return (prv);
}

size_t	ft_mstcksize(t_mstck *stck)
{
	size_t	i;

	i = 0;
	while (stck != NULL)
	{
		stck = stck->next;
		i++;
	}
	return (i);
}

void	ft_mstck_indexing(t_mstck *stck)
{
	t_mstck	*node;
	size_t	i;

	i = 0;
	node = ft_mstckfirst(stck);
	while (node != NULL)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
