/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_small_three.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 09:36:35 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/27 14:08:29 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

static void	cases_des(t_stack **b, t_stack *max, t_stack *min)
{
	if (max->index == 2 && min->index == 0)
	{
		swap_b(b);
		rrotate_b(b);
	}
	else if (max->index == 2)
		rrotate_b(b);
	else if (min->index == 0)
		rotate_b(b);
	else if (min->index == 1)
	{
		rrotate_b(b);
		swap_b(b);
	}
	else
		swap_b(b);
}

static void	cases_asc(t_stack **a, t_stack *max, t_stack *min)
{
	if (max->index == 2)
		swap_a(a);
	else if (min->index == 0)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (max->index == 0 && min->index == 2)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if (min->index == 1)
		rotate_a(a);
	else
		rrotate_a(a);
}

void	ft_three_des_b(t_stack **a, t_stack **b)
{
	t_stack	*max;
	t_stack	*min;

	if (a != NULL && b != NULL)
	{
		if ((*b) != NULL)
		{
			if (ft_stacksize(*b) == 3)
			{
				max = ft_max(*b);
				min = ft_min(*b);
				cases_des(b, max, min);
			}
		}
	}
}

void	ft_three_asc_a(t_stack **a, t_stack **b)
{
	t_stack	*max;
	t_stack	*min;

	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL)
		{
			if (ft_stacksize(*a) == 3)
			{
				max = ft_max(*a);
				min = ft_min(*a);
				cases_asc(a, max, min);
			}
		}
	}
}
