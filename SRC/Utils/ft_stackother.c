/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stackother.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:08:28 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:12:07 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

/*This file contains the functions:
			-ft_stacknew(int content)
			-ft_stacklast(t_stack *stck)
			-ft_stackfirst(t_stack *stck)
			-ft_stacksize(t_stack *stck)
			-ft_indexing(t_stack *stck)
  *ft_stacknew(int content):
  		This function allocates a new node using malloc. 
		If malloc fails the function returns NULL.
		Otherwise, it stores content in the node,
		and sets previous and next to NULL in the node and
		returns the node.
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

t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->content = content;
	node->iter_cnt = content;
	node->index = 0;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stck)
{
	t_stack	*cur;
	t_stack	*prv;

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

t_stack	*ft_stackfirst(t_stack *stck)
{
	t_stack	*cur;
	t_stack	*prv;

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

size_t	ft_stacksize(t_stack *stck)
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

void	ft_indexing(t_stack *stck)
{
	t_stack	*node;
	size_t	i;

	i = 0;
	node = ft_stackfirst(stck);
	while (node != NULL)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
