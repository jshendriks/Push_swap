/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:07:19 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 17:41:38 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../types.h"
# include "../Operations/operations.h"
# include "../Utils/utils.h"

void	radix_sort_asc(t_stack **a, t_stack **b);
/*Sorts the given stack a, using stack b and bitwise operations.*/
void	reverse_order_a(t_stack **a, t_stack **b);
/*Reverses the order of the given stack a.*/
void	reverse_order_b(t_stack **a, t_stack **b);
/*Reverses the order of the given stack b.*/

void	node_placing_asc(t_stack **head, t_stack *node, size_t size, int c);
/*Compares node against all previous nodes in head.*/
void	node_placing_des(t_stack **head, t_stack *node, size_t size, int c);
/*Compares node against all previous nodes in head.*/
void	ft_insertionsort_asc(t_stack **a, int c);
/*Sorts in ascending order the given stack by comparing nodes.*/
void	ft_insertionsort_des(t_stack **a, int c);
/*Sorts in descending order the given stack by comparing nodes.*/

void	ft_smallsort(t_stack **a, t_stack **b);
void	ft_two_asc_a(t_stack **a, t_stack **b);
void	ft_two_des_b(t_stack **a, t_stack **b);
void	ft_three_des_b(t_stack **a, t_stack **b);
void	ft_three_asc_a(t_stack **a, t_stack **b);
void	ft_four(t_stack **a, t_stack **b);
void	ft_five(t_stack **a, t_stack **b);
void	ft_six(t_stack **a, t_stack **b);

#endif
