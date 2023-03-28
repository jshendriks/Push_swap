/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 10:40:43 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/28 11:18:46 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

static int	ft_printfstack(t_mstck *stck)
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

static int	ft_printfnode(t_mstck *node)
{
	int	wrt;

	if (node != NULL)
		wrt = ft_printf("Node: %p, %L, %i, %p \n", node->prev, node->index, node->content, node->next);
	else
		wrt = ft_printf("NULL\n");
	return (wrt);
}

static int	after_first_check(int argc, char *argv[])
{
	t_stack	*temp;
	t_mstck	*a;
	t_mstck	*b;

	temp = ft_makestack_int(argc, argv);
	if (temp == NULL)
		return (0);
	if (check_doubles(temp) == 1)
	{
		a = ft_makemstck_int(argc, argv);
		b = ft_mstcknew(6);
		ft_printf("Input: \n");
		ft_printfstack(a);
		ft_printfstack(b);
		ft_printf("Output: \n");
		ft_printfnode(ft_place(b, &a));
		if (a != NULL)
			ft_mstckclear(&a);
		if (b != NULL)
			ft_mstckclear(&b);
		ft_stackclear(&temp);
		return (1);
	}
	ft_stackclear(&temp);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	rtn;

	if (argc > 1)
	{
		if (check_input_nums(argc, argv) == 1)
		{
			rtn = after_first_check(argc, argv);
			return (rtn);
		}
		else 
			return (0);
	}
	return (0);
}
