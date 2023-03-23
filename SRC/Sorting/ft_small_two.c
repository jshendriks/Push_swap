/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_small_two.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 09:37:00 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/23 09:37:52 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

void	ft_two_asc_a(t_stack **a, t_stack **b)
{
	if (a != NULL && b != NULL)
	{
		if ((*a) != NULL)
		{
			if (ft_stacksize(*a) == 2)
			{
				if ((*a)->content > ((*a)->next)->content)
					swap_a(a);
			}
		}
	}
}

void	ft_two_des_b(t_stack **a, t_stack **b)
{
	if (a != NULL && b != NULL)
	{
		if ((*b) != NULL)
		{
			if (ft_stacksize(*b) == 2)
			{
				if ((*b)->content < ((*b)->next)->content)
					swap_b(b);
			}
		}
	}
}
