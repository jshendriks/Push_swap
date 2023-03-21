/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort_nb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 12:01:56 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 18:03:02 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

static void	comparing(t_stack **a, t_stack **b, t_stack *nodea, t_stack *nodeb)
{
	size_t	r;

	if (nodea->next == NULL)
	{
		if (nodeb->content > nodea->content)
		{
			push_a(a, b);
			rotate_a(a);
		}
		else
		{
			rrotate_a(a);
			push_a(a, b);
			rotate_a_ntimes(a, 2);
		}
	}
	else if (nodeb->content <= nodea->content)
	{
		r = nodea->index;
		rotate_a_ntimes(a, r);
		push_a(a, b);
		rrotate_a_ntimes(a, r);
	}
}

static void	ft_merge(t_stack **a, t_stack **b, size_t sizeb)
{
	t_stack	*nodea;
	t_stack	*nodeb;
	size_t	i;

	i = 0;
	nodea = *a;
	nodeb = *b;
	while (i < sizeb)
	{
		while (nodea && nodeb == (*b))
		{
			comparing(a, b, nodea, nodeb);
			nodea = nodea->next;
		}
		nodeb = *b;
		nodea = *a;
		i++;
	}
}

static void	merge(t_stack **a, t_stack **b, size_t n)
{
	t_stack	*lasta;
	t_stack	*lastb;

	lasta = ft_stacklast(*a);
	lastb = ft_stacklast(*b);
	if ((*b)->content < (*a)->content)
		push_a_ntimes(a, b, n);
	else if (lastb->content > lasta->content)
	{
		push_a_ntimes(a, b, n);
		rotate_a_ntimes(a, n);
	}
	else
		ft_merge(a, b, n);
}

void	ft_four(t_stack **a, t_stack **b)
{
	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL && (*b) == NULL)
		{
			if (ft_stacksize(*a) == 4)
			{
				push_b_ntimes(a, b, 2);
				ft_two_asc_a(a, b);
				ft_two_des_b(a, b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 2);
				else if (((*b)->next) > ((*a)->next))
				{
					push_a_ntimes(a, b, 2);
					rotate_a_ntimes(a, 2);
				}
				else
					ft_merge(a, b, 2);
			}
		}
	}
}

void	ft_five(t_stack **a, t_stack **b)
{
	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL && (*b) == NULL)
		{
			if (ft_stacksize(*a) == 5)
			{
				push_b_ntimes(a, b, 2);
				if (issorted_asc(*a) >= 0)
					ft_three_asc_a(a, b);
				if (issorted_des(*b) >= 0)
					ft_two_des_b(a, b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 2);
				else if (((*b)->next)->content > (((*a)->next)->next)->content)
				{
					push_a_ntimes(a, b, 2);
					rotate_a_ntimes(a, 2);
				}
				else
					merge(a, b, 2);
			}
		}
	}
}

void	ft_six(t_stack **a, t_stack **b)
{
	t_stack	*lastb;
	t_stack	*lasta;

	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL && (*b) == NULL)
		{
			if (ft_stacksize(*a) == 6)
			{
				push_b_ntimes(a, b, 3);
				if (issorted_asc(*a) >= 0)
					ft_three_asc_a(a, b);
				if (issorted_des(*b) >= 0)
					ft_three_des_b(a, b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 3);
				lastb = (((*b)->next)->next);
				lasta = (((*a)->next)->next);
				else if (lastb->content > lasta->content)
				{
					push_a_ntimes(a, b, 3);
					rotate_a_ntimes(a, 3);
				}
				else
					merge(a, b, 3);
			}
		}
	}
}
