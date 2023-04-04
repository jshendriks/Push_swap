/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quirky_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:56:43 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 15:13:57 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

static void	mapping_to_b(t_mstck **a, t_mstck **b)
{
	size_t	sizea;

	push_b_ntimes_mstck(a, b, 2);
	sizea = ft_mstcksize(*a);
	while (sizea > 1)
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
	t_mstck	*max;
	t_mstck	*nodeb;
	t_mstck	*rema;
	size_t	sizeb;

	max = ft_mstckmax(*b);
	sizeb = ft_mstcksize(*b);
	if (max->index != 0)
	{
		if (max->index < (sizeb / 2))
			rotate_b_ntimes_mstck(b, max->index);
		else
			rrotate_b_ntimes_mstck(b, sizeb - (max->index));
	}
	nodeb = *b;
	rema = *a;
	while (nodeb)
	{
		if (nodeb->content > rema->content)
		{
			push_a_mstck(a, b);
			nodeb = *b;
		}
		else
			nodeb = NULL;
	}
	rrotate_a_mstck(a);
	nodeb = *b;
	while (nodeb)
	{
		push_a_mstck(a, b);
		nodeb = *b;
	}
}
/*
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
*/
void	ft_quirkysort(t_mstck **a, t_mstck **b)
{
	if (a != NULL && b != NULL)
	{
		if (*a != NULL && *b == NULL)
		{
//			ft_printf("Mapping\n");
			mapping_to_b(a, b);
//			ft_printf("Sorting mstck a\n");
		//	ft_three_asc(a, b);
//			ft_printf("Going back to mstck b\n");
			back_to_a(a, b);
		}
	}
}
