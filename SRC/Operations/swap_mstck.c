/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_mstck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:48:08 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 14:49:57 by jhendrik      ########   odam.nl         */
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

void	swap_a_mstck(t_mstck **a)
{
	ft_swap_mstck(a);
	ft_printf("sa\n");
}

void	swap_b_mstck(t_mstck **b)
{
	ft_swap_mstck(b);
	ft_printf("sb\n");
}

void	swap_ab_mstck(t_mstck **a, t_mstck **b)
{
	ft_swap_ab_mstck(a, b);
	ft_printf("ss\n");
}
