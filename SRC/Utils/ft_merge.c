/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_merge.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 18:07:21 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 18:12:45 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

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

void	merge(t_stack **a, t_stack **b, size_t n)
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
