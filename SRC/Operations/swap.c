/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:43:16 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 12:46:28 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

/*This file contains the functions:
				-swap_a(t_stack **a)
				-swap_b(t_stack **b)
				-swap_ab(t_stack **a, t_stack **b)
 *swap_a(t_stack **a):
 		Calls ft_swap(a) and prints message.
 *swap_b(t_stack **b):
 		Calls ft_swap(b) and prints message.
 *swap_ab(t_stack **a, t_stack **b)
 		Calls ft_swap_ab() and prints message.
 */

void	swap_a(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack **a, t_stack **b)
{
	ft_swap_ab(a, b);
	ft_printf("ss\n");
}
