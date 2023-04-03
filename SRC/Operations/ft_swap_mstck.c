/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap_mstck.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:45:26 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 17:37:42 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
   			-ft_swap2(t_stack **a)
			-ft_swap_more(t_stack **a)
			-ft_swap(t_stack **a)
			-ft_swap_ab(t_stack **a, t_stack **b)
 *ft_swap2(t_stack **a):
		This function swaps two elements in a stack
		which contains just two elements.
 *ft_swap_more(t_stack **a):
		This function swaps two elements in a stack
		which contains more than two elements.
 *ft_swap(t_stack **a):
		This function swaps the first two nodes of the
		given stack a, if a contains two or more nodes.
 *ft_swap_ab(t_stack **a, t_stack **b):
		Calls ft_swap() on both stacks.
 */

static void	ft_swap2(t_mstck **a)
{
	t_mstck	*first;
	t_mstck	*last;

	first = *a;
	last = first->next;
	first->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	*a = last;
}

static void	ft_swap_more(t_mstck **a)
{
	t_mstck	*tmp1;
	t_mstck	*tmp2;
	t_mstck	*tmp3;

	tmp1 = *a;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	tmp3->prev = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp2->next;
	tmp2->prev = NULL;
	tmp2->next = tmp1;
	*a = tmp2;
}

void	ft_swap_mstck(t_mstck **a)
{
	if (a != NULL)
	{
		if (*a != NULL)
		{
			if ((*a)->next != NULL)
			{
				if (((*a)->next)->next == NULL)
					ft_swap2(a);
				else
					ft_swap_more(a);
				(*a)->index = 0;
				(*a)->next->index = 1;
			}
		}
	}
}

void	ft_swap_ab_mstck(t_mstck **a, t_mstck **b)
{
	ft_swap_mstck(a);
	ft_swap_mstck(b);
}
