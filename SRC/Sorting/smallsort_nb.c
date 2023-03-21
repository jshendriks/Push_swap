/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort_nb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 12:01:56 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 18:09:21 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

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
				merge(a, b, 2);
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
				merge(a, b, 2);
			}
		}
	}
}

void	ft_six(t_stack **a, t_stack **b)
{
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
				merge(a, b, 3);
			}
		}
	}
}
