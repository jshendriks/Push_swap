/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcmoves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 17:28:27 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/27 18:27:02 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	calcmoves_upup(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min)
{
	t_moves	*move_upup;

	move_upup = ((node->map)->upup);
	move_upup->ra = (node->index);
	if (node->content < min->content)
	{
		move_upup->rb = max->index;
		(move_upup->pb) += 1;
	}
	else if (node->content > max->content)
	{
		move_upup->rb = max->index;
		(move_upup->pb) += 1;
	}
	else
	{
		//find a way to determine where the node belongs in b
		//then enter the moves in the move_upup to get it there
	}
}

void	ft_calcmap(t_mstck *node, t_mstck **b)
{
	t_mstck	max;
	t_mstck	min;

	if (b != NULL)
	{
		if (node != NULL && *b != NULL)
		{
			max = ft_mstckmax(*b);
			min = ft_mstckmin(*b);
		}
	}
}
