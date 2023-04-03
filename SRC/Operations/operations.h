/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 17:53:49 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 15:12:08 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../Utils/utils.h"
# include "../types.h"

//BASIC OPERATIONS TO SORT WITH ---------------
void	ft_swap(t_stack **a);
/*This function swaps the first two elements
  of the stack pointed to by *a.
  It only does this, if the stack has two or more elements.*/
void	ft_swap_ab(t_stack **a, t_stack **b);
/*This function swaps the first two elements
  of both stack *a and *b.*/

//EXTRA OPERATIONS TO SORT WITH -----------------
void	rotate_a_ntimes(t_stack **a, size_t n);
/*Calls rotate_a() n times.*/
void	rotate_b_ntimes(t_stack **b, size_t n);
/*Calls rotate_b() n times.*/
void	rrotate_a_ntimes(t_stack **a, size_t n);
/*Calls rrotate_a() n times.*/
void	rrotate_b_ntimes(t_stack **b, size_t n);
/*Calls rrotate_b() n times.*/
void	indexswap_a(t_stack **a, size_t n, size_t size);
/*Swaps the element at index n with the next node.*/
void	indexswap_b(t_stack **b, size_t n, size_t size);
/*Swaps the element at index n with the next node.*/
void	push_a_ntimes(t_stack **a, t_stack **b, size_t n);
/*Calls push_a() n times.*/
void	push_b_ntimes(t_stack **a, t_stack **b, size_t n);
/*Calls push_b() n times.*/
void	pick_rotate(t_stack **a, size_t n, int c);
/*Applies rotate or reverse rotate n times,
 * depending on which one is more efficient.*/
void	pick_rrotate(t_stack **a, size_t n, int c);
/*Applies reverse rotate or rotate n times,
 * depending on which one is more efficient.*/

//OPERATIONS WITH MESSAGES STACK-------------------
void	swap_a(t_stack **a);
/*Calls ft_swap() and prints message.*/
void	swap_b(t_stack **b);
/*Calls ft_swap() and prints message.*/
void	swap_ab(t_stack **a, t_stack **b);
/*Calls ft_swap_ab() and prints message.*/
void	push_a(t_stack **a, t_stack **b);
/*Calls ft_push_a() and prints message.*/
void	push_b(t_stack **a, t_stack **b);
/*Calls ft_push_b() and prints message.*/
void	rotate_a(t_stack **a);
/*Calls rotate() and prints message.*/
void	rotate_b(t_stack **b);
/*Calls rotate() and prints message.*/
void	rotate_ab(t_stack **a, t_stack **b);
/*Calls ft_rotate_ab() and prints message.*/
void	rrotate_a(t_stack **a);
/*Calls rrotate() and prints message.*/
void	rrotate_b(t_stack **b);
/*Calls rrotate() and prints message.*/
void	rrotate_ab(t_stack **a, t_stack **b);
/*Calls ft_rrotate_ab() and prints message.*/

//OPERATIONS WITH MESSAGES MSTCK -------------------
void	swap_a_mstck(t_mstck **a);
/*Calls ft_swap() and prints message.*/
void	swap_b_mstck(t_mstck **b);
/*Calls ft_swap() and prints message.*/
void	swap_ab_mstck(t_mstck **a, t_mstck **b);
/*Calls ft_swap_ab() and prints message.*/
void	push_a_mstck(t_mstck **a, t_mstck **b);
/*Calls ft_push_a() and prints message.*/
void	push_b_mstck(t_mstck **a, t_mstck **b);
/*Calls ft_push_b() and prints message.*/
void	rotate_a_mstck(t_mstck **a);
/*Calls rotate() and prints message.*/
void	rotate_b_mstck(t_mstck **b);
/*Calls rotate() and prints message.*/
void	rotate_ab_mstck(t_mstck **a, t_mstck **b);
/*Calls ft_rotate_ab() and prints message.*/
void	rrotate_a_mstck(t_mstck **a);
/*Calls rrotate() and prints message.*/
void	rrotate_b_mstck(t_mstck **b);
/*Calls rrotate() and prints message.*/
void	rrotate_ab_mstck(t_mstck **a, t_mstck **b);
/*Calls ft_rrotate_ab() and prints message.*/

//EXTRA OPERATIONS TO SORT WITH MSTCK-----------------
void	rotate_a_ntimes_mstck(t_mstck **a, size_t n);
/*Calls rotate_a() n times.*/
void	rotate_b_ntimes_mstck(t_mstck **b, size_t n);
/*Calls rotate_b() n times.*/
void	rrotate_a_ntimes_mstck(t_mstck **a, size_t n);
/*Calls rrotate_a() n times.*/
void	rrotate_b_ntimes_mstck(t_mstck **b, size_t n);
/*Calls rrotate_b() n times.*/
void	push_a_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n);
/*Calls push_a() n times.*/
void	push_b_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n);
/*Calls push_b() n times.*/
void	rotate_ab_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n);
/*...*/
void	rrotate_ab_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n);

//BASIC OPERATIONS TO SORT WITH MSTCK---------------
void	ft_swap_mstck(t_mstck **a);
/*This function swaps the first two elements
  of the stack pointed to by *a.
  It only does this, if the stack has two or more elements.*/
void	ft_swap_ab_mstck(t_mstck **a, t_mstck **b);
/*This function swaps the first two elements
  of both stack *a and *b.*/
#endif
