/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_sorting.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:24:45 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:45:08 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "sorting.h"

static int	ft_free_mstck(t_mstck **a, t_mstck **b)
{
	if (a == NULL)
	{
		if (b != NULL)
			ft_mstckclear(b);
	}
	else
	{
		ft_mstckclear(a);
		if (b != NULL)
			ft_mstckclear(b);
	}
	return (0);
}

static int	ft_errormessage_mstck(t_mstck **a, t_mstck **b, char *mess, int fd)
{
	ft_putstr_fd(mess, fd);
	return (ft_free_mstck(a, b));
}

static int	quirkysorting(int argc, char *argv[])
{
	t_mstck	*ac;
	t_mstck	*bc;

	ac = ft_makemstck_int(argc, argv);
	bc = NULL;
	if (ac == NULL)
		return (ft_errormessage_mstck(&ac, &bc, "Error\n", 2));
	else
		ft_quirkysort(&ac, &bc);
	if (ac != NULL)
		ft_mstckclear(&ac);
	if (bc != NULL)
		ft_mstckclear(&bc);
	return (1);
}

int	ft_sorting(int argc, char *argv[], t_stack **a)
{
	t_stack	*b;
	size_t	size_a;

	size_a = ft_stacksize(*a);
	b = NULL;
	if (issorted_des(*a) == -1)
	{
		if (size_a < 7)
			ft_smallsort(a, &b);
		else
			reverse_order_a(a, &b);
	}
	else
	{
		if (size_a < 7)
			ft_smallsort(a, &b);
		else if (size_a < 16)
			ft_insertionsort_asc(a, 'a');
		else
			return (quirkysorting(argc, argv));
	}
	if (b != NULL)
		ft_stackclear(&b);
	return (1);
}
