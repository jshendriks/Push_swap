/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_best.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:05:17 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:54:57 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static t_mstck	*find_marked(t_mstck **a)
{
	t_mstck	*nodea;

	nodea = *a;
	while (nodea)
	{
		if (nodea->mark != 0)
			return (nodea);
		nodea = nodea->next;
	}
	return (NULL);
}

static void	exec_rotates(t_moves *move, t_mstck **a, t_mstck **b)
{
	if (move->ra != 0)
		rotate_a_ntimes_mstck(a, move->ra);
	if (move->rb != 0)
		rotate_b_ntimes_mstck(b, move->rb);
	if (move->rr != 0)
		rotate_ab_ntimes_mstck(a, b, move->rr);
	if (move->rra != 0)
		rrotate_a_ntimes_mstck(a, move->rra);
	if (move->rrb != 0)
		rrotate_b_ntimes_mstck(b, move->rrb);
	if (move->rrr != 0)
		rrotate_ab_ntimes_mstck(a, b, move->rrr);
}

static void	exec_swaps_push(t_moves *move, t_mstck **a, t_mstck **b)
{
	if (move->sa != 0)
		swap_a_mstck(a);
	if (move->sb != 0)
		swap_b_mstck(b);
	if (move->ss != 0)
		swap_ab_mstck(a, b);
	if (move->pa != 0)
		push_a_ntimes_mstck(a, b, move->pa);
	if (move->pb != 0)
		push_b_ntimes_mstck(a, b, move->pb);
}

static void	exec_moves(t_moves *move, t_mstck **a, t_mstck **b)
{
	exec_rotates(move, a, b);
	exec_swaps_push(move, a, b);
}

void	exec_best(t_mstck **a, t_mstck **b)
{
	t_mstck	*marked;

	marked = find_marked(a);
	if (marked != NULL)
	{
		if (marked->mark == 1)
			exec_moves((marked->map)->upup, a, b);
		else if (marked->mark == 2)
			exec_moves((marked->map)->updown, a, b);
		else if (marked->mark == 3)
			exec_moves((marked->map)->downdown, a, b);
		else
			exec_moves((marked->map)->downup, a, b);
	}
}
