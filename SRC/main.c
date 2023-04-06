/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 12:14:02 by jhendrik      ########   odam.nl         */
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
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		rtn;

	tmpa = ft_makestack_int(argc, argv);
	tmpb = NULL;
	if (tmpa == NULL)
		return (ft_errormessage(&tmpa, &tmpb, "Error\n", 2));
	if (check_doubles(tmpa) == 1)
	{
		if (issorted_asc(tmpa) == 0)
		{
			rtn = ft_sorting(argc, argv, &tmpa);
			if (tmpa != NULL)
				ft_stackclear(&tmpa);
			return (rtn);
		}
		else
			return (ft_free(&tmpa, &tmpb));
	}
	else
		return (ft_errormessage(&tmpa, &tmpb, "Error\n", 2));
}

int	main(int argc, char *argv[])
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		rtn;

	tmpa = NULL;
	tmpb = NULL;
	if (argc > 1)
	{
		if (check_input_nums(argc, argv) == 1)
		{
			rtn = after_first_check(argc, argv);
			return (rtn);
		}
		else
			return (ft_errormessage(&tmpa, &tmpb, "Error\n", 2));
	}
	return (0);
}
