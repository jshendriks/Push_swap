/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:18:45 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:23:47 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
   			-ft_push_a(t_stack **a, t_stack **b)
			-ft_push_b(t_stack **a, t_stack **b)
			-push_a(t_stack **a, t_stack **b)
			-push_b(t_stack **a, t_stack **b)
 *ft_push_a(t_stack **a, t_stack **b):
		This function adds the first node in the stack 
		pointed to by *b, to the stack pointed to by *a.
		If *b is NULL, the function does not do anything.
		If the first node is not the only node, 
		it sets the second node as the first node of *b
		and then adds the previous first node to stack *a
		by calling ft_stackadd_front().
		a and b should be pointing to the beginning
		of the respective stacks.
 *ft_push_b(t_stack **a, t_stack **b):
		Same as push_a(), but then other way around.
 *push_a(t_stack **a, t_stack **b):
 		Calls the function ft_push_a() and prints message.
 *push_b(t_stack **a, t_stack **b):
 		Calls the function ft_push_b() and prints message.
 */

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b1;
	t_stack	*tmp_b2;

	if (b != NULL)
	{
		if (*b != NULL)
		{
			tmp_b1 = *b;
			tmp_b2 = tmp_b1->next;
			if (tmp_b2 != NULL)
			{
				*b = tmp_b2;
				tmp_b2->prev = NULL;
				tmp_b1->next = NULL;
			}
			else
				*b = NULL;
			ft_stackadd_front(a, tmp_b1);
			ft_indexing(*a);
			if (*b != NULL)
				ft_indexing(*b);
		}
	}
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;

	if (*a != NULL)
	{
		tmp_a = *a;
		if (tmp_a->next != NULL)
		{
			tmp_a->next->prev = NULL;
			*a = tmp_a->next;
			tmp_a->next = NULL;
		}
		else
			*a = NULL;
		ft_stackadd_front(b, tmp_a);
		ft_indexing(*a);
		ft_indexing(*b);
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	ft_push_a(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	ft_push_b(a, b);
	ft_printf("pb\n");
}
