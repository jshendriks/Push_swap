/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:39:15 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

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
