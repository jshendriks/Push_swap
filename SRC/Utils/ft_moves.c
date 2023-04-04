/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_moves.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 11:40:30 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:58:42 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static void	cleanup_rotate(t_moves *move)
{
	size_t	temp;

	if (move->ra != 0 && move->rb != 0)
	{
		if (move->ra <= move->rb)
			temp = move->ra;
		else
			temp = move->rb;
		move->rr = temp;
		(move->ra) -= temp;
		(move->rb) -= temp;
	}
	if (move->rra != 0 && move->rrb != 0)
	{
		if (move->rra <= move->rrb)
			temp = move->rra;
		else
			temp = move->rrb;
		move->rrr = temp;
		(move->rra) -= temp;
		(move->rrb) -= temp;
	}
}

static void	cleanup_swap(t_moves *move)
{
	size_t	temp;

	if (move->sa != 0 && move->sb != 0)
	{
		if (move->sa <= move->sb)
			temp = move->sa;
		else
			temp = move->sb;
		move->ss = temp;
		(move->sa) -= temp;
		(move->sb) -= temp;
	}
}

static void	calc_total(t_moves *move)
{
	(move->total) += ((move->ra) + (move->rb) + (move->rr));
	(move->total) += ((move->rra) + (move->rrb) + (move->rrr));
	(move->total) += ((move->sa) + (move->sb) + (move->ss));
	(move->total) += ((move->pa) + (move->pb));
}

void	cleanup_moves(t_moves *move)
{
	if (move != NULL)
	{
		cleanup_rotate(move);
		cleanup_swap(move);
		calc_total(move);
	}
}
