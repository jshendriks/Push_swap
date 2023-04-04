/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quirky_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:56:43 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 11:56:27 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

static void	mapping_to_b(t_mstck **a, t_mstck **b)
{
	size_t	sizea;

	push_b_ntimes_mstck(a, b, 2);
	sizea = ft_mstcksize(*a);
	while (sizea > 3)
	{
		set_markszero(a);
		set_mapszero(a);
		ft_calcmaps(a, b);
		ft_markbest(a);
		exec_best(a, b);
		sizea = ft_mstcksize(*a);
	}
}

static void	back_to_a(t_mstck **a, t_mstck **b)
{
	size_t	r;
	size_t	sizea;
	t_mstck	*nodeb;
	t_mstck	*tmp;

	nodeb = *b;
	while (nodeb)
	{
//		if (nodeb != NULL)
//			ft_printf("Node: %p, %L, %i, %p \n", nodeb->prev, nodeb->index, nodeb->content, nodeb->next);
//		else
//			ft_printf("Node: NULL\n");
		tmp = ft_place_asc(nodeb, a);
//		if (tmp != NULL)
//			ft_printf("tmp: %p, %L, %i, %p \n", tmp->prev, tmp->index, tmp->content, tmp->next);
//		else
//			ft_printf("tmp: NULL\n");
		r = tmp->index;
		sizea = ft_mstcksize(*a);
		if (r < (sizea / 2))
			rotate_a_ntimes_mstck(a, r);
		else
			rrotate_a_ntimes_mstck(a, sizea - r);
		push_a_mstck(a, b);
		nodeb = *b;
	}
	tmp = ft_mstckmin(*a);
	r = tmp->index;
	if (r < (sizea / 2))
		rotate_a_ntimes_mstck(a, r);
	else
		rrotate_a_ntimes_mstck(a, sizea - r);
}

static void	cases_asc(t_mstck **a, t_mstck *max, t_mstck *min)
{
	if (max->index == 2)
		swap_a_mstck(a);
	else if (min->index == 0)
	{
		swap_a_mstck(a);
		rotate_a_mstck(a);
	}
	else if (max->index == 0 && min->index == 2)
	{
		rotate_a_mstck(a);
		swap_a_mstck(a);
	}
	else if (min->index == 1)
		rotate_a_mstck(a);
	else
		rrotate_a_mstck(a);
}

static void	ft_three_asc(t_mstck **a, t_mstck **b)
{
	t_mstck	*max;
	t_mstck	*min;

	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL)
		{
			if (ft_mstcksize(*a) == 3)
			{
				max = ft_mstckmax(*a);
				min = ft_mstckmin(*a);
				cases_asc(a, max, min);
			}
		}
	}
}

void	ft_quirkysort(t_mstck **a, t_mstck **b)
{
	if (a != NULL && b != NULL)
	{
		if (*a != NULL && *b == NULL)
		{
//			ft_printf("Mapping\n");
			mapping_to_b(a, b);
//			ft_printf("Sorting mstck a\n");
			ft_three_asc(a, b);
//			ft_printf("Going back to mstck b\n");
			back_to_a(a, b);
		}
	}
}
