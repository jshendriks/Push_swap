/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/20 11:35:52 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

static int	ft_sorting(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = ft_stacksize(*a);
	if (issorted_des(a) == -1)
	{
		if (size_a < 7)
			ft_smallsort(a, b);
		else
			reverse_order_a(a, b);
	}
	else
	{
		if (size_a < 64)
			ft_insertionsort_asc(a, 'a');
		else
			radix_sort_asc(a, b);
	}
	return (1);
}

static int	ft_free(t_stack **a, t_stack **b)
{
	if (a == NULL)
	{
		if (b != NULL)
			ft_stackclear(b);
	}
	else
	{
		ft_stackclear(a);
		if (b != NULL)
			ft_stackclear(b);
	}
	return (0);
}

static int	ft_error(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	return (ft_free(a, b));
}

static int	after_first_check(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = ft_makestack_int(argc, argv);
	b = NULL;
	if (a == NULL)
		return (ft_error(&a, &b));
	if (check_doubles(a) == 1)
	{
		if (issorted_asc(a) >= 0)
			return (ft_sorting(&a, &b));
		else
			return (ft_error(&a, &b));
	}
	else
		return (ft_error(&a, &b));
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		rtn;

	a = NULL;
	b = NULL;
	if (check_input_nums(argc, argv) == 1)
	{
		rtn = after_first_check(argc, argv);
		if (a != NULL)
		{
			ft_stackclear(&a);
			if (b != NULL)
				ft_stackclear(&b);
		}
		return (rtn);
	}
	else
		return (ft_error(&a, &b));
}
