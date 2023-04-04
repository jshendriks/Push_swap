/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 14:28:42 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

/*static int	ft_printfstack(t_mstck *stck)
{
	t_mstck	*tmp;
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
			wrt = ft_printf("Node %i: %p, %L, %i, %i, %p", i, tmp->prev, tmp->index, tmp->content, tmp->mark, tmp->next);
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

static int	issorted_asc_mstck(t_mstck *a)
{
	t_mstck	*node;

	node = a;
	if (a == NULL)
		return (-2);
	while (node != NULL && node->next != NULL)
	{
		if (node->content > node->next->content)
			return (node->index);
		node = node->next;
	}
	return (-1);
}
*/
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
static int	ft_sorting(int argc, char *argv[], t_stack **a)
{
	t_stack	*b;
	t_mstck	*ac;
	t_mstck	*bc;
	size_t	size_a;

	size_a = ft_stacksize(*a);
	b = NULL;
	bc = NULL;
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
		else if (size_a < 32)
			ft_insertionsort_asc(a, 'a');
		else
		{
			ac = ft_makemstck_int(argc, argv);
			if (ac == NULL)
				return (ft_errormessage_mstck(&ac, &bc, "Error\n", 2));
			else
				ft_quirkysort(&ac, &bc);
		//	ft_printf("Stack a\n");
		//	ft_printfstack(ac);
		//	ft_printf("Stack b\n");
		//	ft_printfstack(bc);
		//	ft_printf("It goes wrong on index %i\n", issorted_asc_mstck(ac));
			if (ac != NULL)
				ft_mstckclear(&ac);
			if (bc != NULL)
				ft_mstckclear(&bc);
		}
	}
	if (b != NULL)
		ft_stackclear(&b);
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

static int	ft_errormessage(t_stack **a, t_stack **b, char *mess, int fd)
{
	ft_putstr_fd(mess, fd);
	return (ft_free(a, b));
}

static int	after_first_check(int argc, char *argv[])
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		rtn;

	tmp = ft_makestack_int(argc, argv);
	tmp2 = NULL;
	if (tmp == NULL)
		return (ft_errormessage(&tmp, &tmp2, "Error\n", 2));
	if (check_doubles(tmp) == 1)
	{
		if (issorted_asc(tmp) >= 0)
		{
			rtn = ft_sorting(argc, argv, &tmp);
			if (tmp != NULL)
				ft_stackclear(&tmp);
			return (rtn);
		}
		else
			return (ft_errormessage(&tmp, &tmp2, "Already sorted\n", 2));
	}
	else
		return (ft_errormessage(&tmp, &tmp2, "Error\n", 2));
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		rtn;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (check_input_nums(argc, argv) == 1)
		{
			rtn = after_first_check(argc, argv);
			return (rtn);
		}
		else
			return (ft_errormessage(&a, &b, "Error\n", 2));
	}
	return (0);
}
