/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort_nb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 12:01:56 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 14:15:29 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

void	ft_two_asc_a(t_stack **a)
{
	if (a != NULL)
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

void	ft_two_des_b(t_stack **a)
{
	if (a != NULL)
	{
		if ((*a) != NULL)
		{
			if (ft_stacksize(*a) == 2)
			{
				if ((*a)->content < ((*a)->next)->content)
					swap_b(a);
			}
		}
	}
}

void	ft_three_des_b(t_stack **a)
{
	t_stack	*max;
	t_stack	*min;

	if (a != NULL)
	{
		if ((*a) != NULL)
		{
			if (ft_stacksize(*a) == 3)
			{
				max = ft_max(*a);
				min = ft_min(*a);
				if (max->index == 2 && min->index == 0)
				{
					swap_b(a);
					rrotate_b(a);
				}
				else if (max->index == 2)
					rrotate_b(a);
				else if (min->index == 0)
					rotate_b(a);
				else if (min->index == 1)
				{
					rrotate_b(a);
					swap_b(a);
				}
				else
					swap_b(a);
			}
		}
	}
}

void	ft_three_asc_a(t_stack **a)
{
	t_stack	*max;
	t_stack	*min;

	if (a != NULL)
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

void	merge(t_stack **a, t_stack **b, size_t sizeb)
{
	t_stack	*nodea;
	t_stack	*nodeb;
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	nodea = *a;
	nodeb = *b;
	while (i < sizeb)
	{
		while (nodea && nodeb == (*b))
		{
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
			nodea = nodea->next;
		}
		nodeb = *b;
		nodea = *a;
		i++;
	}
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
				ft_two_asc_a(a);
				ft_two_des_b(b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 2);
				else if (((*b)->next) > ((*a)->next))
				{
					push_a_ntimes(a, b, 2);
					rotate_a_ntimes(a, 2);
				}
				else
				{
					if ((*b)->content <= ((*a)->next)->content)
					{
						rotate_a(a);
						push_a(a, b);
						rrotate_a(a);
					}
					else
					{
						push_a(a, b);
						rotate_a(a);
					}

				}
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
				ft_three_asc_a(a);
				ft_two_des_b(b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 2);
				else if (((*b)->next)->content > (((*a)->next)->next)->content)
				{
					push_a_ntimes(a, b, 2);
					rotate_a_ntimes(a, 2);
				}
				else
				{

				}
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
				ft_three_asc_a(a);
				ft_three_des_b(b);
				if ((*b)->content < (*a)->content)
					push_a_ntimes(a, b, 3);
				else if ((((*b)->next)->next)->content > (((*a)->next)->next)->content)
				{
					push_a_ntimes(a, b, 3);
					rotate_a_ntimes(a, 3);
				}
				else
				{

				}
			}
		}
	}
}
