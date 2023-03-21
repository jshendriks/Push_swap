/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_smallsort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 11:37:48 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 15:56:39 by jhendrik      ########   odam.nl         */
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
				if (max->index == 2)
					swap_a(a);
				else if (min->index == 0)
				{
					rotate_a(a);
					swap_a(a);
					rrotate_a(a);
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
		}
	}
}

void	ft_smallsort(t_stack **a, t_stack **b)
{
	const t_stckfnc	jmptbl[] = {
			NULL,
			NULL,
			&ft_two_asc_a,
			&ft_three_asc_a,
			&ft_four,
			&ft_five,
			&ft_six
		};
	int					index;
	
	if (a != NULL && b != NULL)
	{
		if (*b == NULL && *a != NULL)
		{
			index = (int)ft_stacksize(*a);
			if (index > 1)
				jmptbl[index](a, b);
		}
	}
}
