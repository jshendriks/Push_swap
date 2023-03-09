/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:46:42 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 19:09:14 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "src.h"

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack	*b;

	if (check_input_nums(argc, argv) == 1)
	{
		a = ft_makestack_int(argc, argv);
		if (a == NULL)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (check_doubles(a) == 1)
		{
			b = NULL;
			if (issorted_asc(a) >= 0)
			{
				if (issorted_des(a) == -1)
				{
					//depending on size of a
					//sort or reverse order
				}
				else
				{
					//depending on size of a
					//call sorting algorithms
				}
			}
		}
		else
			write(2, "Error\n", 6); 
		ft_stackclear(&a);
	}
	else
		write(2, "Error\n", 6);
}
