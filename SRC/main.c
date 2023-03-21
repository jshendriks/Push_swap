/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 15:35:12 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

static int	ft_sorting(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = ft_stacksize(*a);
	if (issorted_des(*a) == -1)
	{
		if (size_a < 7)
			ft_smallsort(a, b);
		else
			reverse_order_a(a, b);
	}
	else
	{
		if (size_a < 7)
			ft_smallsort(a, b);
		else if (size_a < 64)
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
	write(1, "Error\n", 6);
	return (ft_free(a, b));
}

static int	ft_printfstack(t_stack *stck)
{
	t_stack	*tmp;
	int		i;
	int		wrt;
	int		rtn;

	tmp = stck;
	i = 0;
	rtn = 0;
	if (stck == NULL)
		rtn = ft_printf("NULL\n");
	else
	{
		while (tmp != NULL)
		{
			wrt = ft_printf("Node %i: %p, %L, %i, %p", i, tmp->prev, tmp->index, tmp->content, tmp->next);
			if (wrt == -1)
				return (-1);
			wrt = ft_printf("\t Own ptr: %p\n", tmp);
			if (wrt == -1)
				return (-1);
			rtn += wrt;
			tmp = tmp->next;
			i++;
		}
	}
	return (rtn);
}

static int	after_first_check(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		rtn;

	a = ft_makestack_int(argc, argv);
	ft_printf("Stack a before sorting:\n");
	ft_printfstack(a);
	b = NULL;
	if (a == NULL)
		return (ft_error(&a, &b));
	if (check_doubles(a) == 1)
	{
		if (issorted_asc(a) >= 0)
		{
			rtn = ft_sorting(&a, &b);
			ft_printf("Stack a after sorting:\n");
			ft_printfstack(a);
			ft_printf("Stack b after sorting:\n");
			ft_printfstack(b);
			if (a != NULL)
				ft_stackclear(&a);
			if (b != NULL)
				ft_stackclear(&b);
			return (rtn);
		}
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
		return (rtn);
	}
	else
		return (ft_error(&a, &b));
}
