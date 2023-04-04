/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calcmoves_down.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:35:50 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 17:17:01 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static void	check_updown(t_moves *move, size_t temp, size_t sizeb)
{
	if (temp == sizeb)
		move->rrb = 0;
	else
		move->rrb = temp;
	(move->pb) += 1;
}

void	calcmoves_ud(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min)
{
	t_moves	*move;
	t_mstck	*place;
	size_t	sizeb;

	move = ((node->map)->updown);
	move->ra = (node->index);
	sizeb = ft_mstcksize(*b);
	if (node->content < min->content)
		check_updown(move, sizeb - (max->index), sizeb);
	else if (node->content > max->content)
		check_updown(move, sizeb - (max->index), sizeb);
	else
	{
		place = ft_place(node, b);
		if (place != NULL)
			check_updown(move, sizeb - (place->index), sizeb);
	}
	cleanup_moves(move);
}

void	calcmoves_ddown(t_mstck *node, t_mstck **b, t_mstck *max, size_t sizea)
{
	t_moves	*move;
	t_mstck	*place;
	t_mstck	*min;
	size_t	sizeb;
	size_t	temp;

	move = ((node->map)->downdown);
	temp = sizea - (node->index);
	min = ft_mstckmin(*b);
	if (temp != sizea)
		move->rra = temp;
	sizeb = ft_mstcksize(*b);
	if (node->content < min->content)
		check_updown(move, sizeb - (max->index), sizeb);
	else if (node->content > max->content)
		check_updown(move, sizeb - (max->index), sizeb);
	else
	{
		place = ft_place(node, b);
		if (place != NULL)
			check_updown(move, sizeb - (place->index), sizeb);
	}
	cleanup_moves(move);
}

void	calcmoves_du(t_mstck *node, t_mstck **b, t_mstck *max, size_t sizea)
{
	t_moves	*move;
	t_mstck	*place;
	t_mstck	*min;
	size_t	temp;

	move = ((node->map)->downup);
	temp = sizea - (node->index);
	min = ft_mstckmin(*b);
	if (temp != sizea)
		move->rra = temp;
	if ((node->content < min->content) || (node->content > max->content))
	{
		move->rb = max->index;
		(move->pb) += 1;
	}
	else
	{
		place = ft_place(node, b);
		if (place != NULL)
			move->rb = place->index;
		(move->pb) += 1;
	}
	cleanup_moves(move);
}
