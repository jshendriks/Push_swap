/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertionsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:12:58 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 18:15:09 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

/* This file contains the functions:
			-node_placing_asc(t_stack **head, t_stack *node)
			-node_placing_des(t_stack **head, t_stack *node)
			-ft_insertionsort_asc(t_stack **a)
			-ft_insertionsort_des(t_stack **a)
	*node_placing_asc(t_stack **head, t_stack *node)
		This function checks node against all the previous stack elements.
		If the node is smaller than one of the previous stack elements
		it will be moved appropriately. 
	*node_placing_des(t_stack **head, t_stack *node)
		This function checks node against all the previous stack elements.
		If the node is bigger than one of the previous stack elements
		it will be moved appropriately.
	*ft_insertionsort_asc(t_stack **a)
		This function iterates through the given stack pointed to by a,
		checking whether two neighbouring elements are in ascending order.
		If the elements are not in ascending order, they are swapped
		and the smaller element is checked against all the elements before it.
	*ft_insertionsort_des(t_stack **a)
		This function iterates through the given stack pointed to by a,
		checking whether two neighbouring elements are in descending order.
		If the elements are not in ascending order, they are wapped
		and the bigger element is checked against all the elements before it.
	*/

void	node_placing_asc(t_stack **head, t_stack *node, size_t size, int c)
{
	size_t	r;
	t_stack	*cmp;

	if (head != NULL)
	{
		if (node != NULL && *head != NULL)
		{
			cmp = node->prev;
			while (cmp != NULL)
			{
				if (node->content < cmp->content)
				{
					r = cmp->index;
					if (c == 'a')
						indexswap_a(head, r, size);
					else
						indexswap_b(head, r, size);
					cmp = node->prev;
				}
				else
					cmp = cmp->prev;
			}
		}
	}
}

void	node_placing_des(t_stack **head, t_stack *node, size_t size, int c)
{
	size_t	r;
	t_stack	*cmp;

	if (head != NULL)
	{
		if (node != NULL && *head != NULL)
		{
			cmp = node->prev;
			while (cmp != NULL)
			{
				if (node->content > cmp->content)
				{
					r = cmp->index;
					if (c == 'a')
						indexswap_a(head, r, size);
					else
						indexswap_b(head, r, size);
					cmp = node->prev;
				}
				else
					cmp = cmp->prev;
			}
		}
	}
}

void	ft_insertionsort_asc(t_stack **a, int c)
{
	t_stack	*node1;
	t_stack	*node2;
	size_t	r;
	size_t	size;

	if (a != NULL && *a != NULL)
	{
		node1 = *a;
		node2 = node1->next;
		size = ft_stacksize(*a);
		while (node2 != NULL)
		{
			if (node1->content > node2->content)
			{
				r = node1->index;
				if (c == 'a')
					indexswap_a(a, r, size);
				else
					indexswap_b(a, r, size);
				node_placing_asc(a, node2, size, c);
			}
			node1 = node2;
			node2 = node2->next;
		}
	}
}

void	ft_insertionsort_des(t_stack **a, int c)
{
	t_stack	*node1;
	t_stack	*node2;
	size_t	r;
	size_t	size;

	if (a != NULL && *a != NULL)
	{
		node1 = *a;
		node2 = node1->next;
		size = ft_stacksize(*a);
		while (node2 != NULL)
		{
			if (node1->content < node2->content)
			{
				r = node1->index;
				if (c == 'a')
					indexswap_a(a, r, size);
				else
					indexswap_b(a, r, size);
				node_placing_des(a, node2, size, c);
			}
			node1 = node2;
			node2 = node2->next;
		}
	}
}
