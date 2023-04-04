/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcmoves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 17:28:27 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 17:17:23 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	calcmoves_upup(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min)
{
	t_moves	*move_upup;
	t_mstck	*place;

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
		place = ft_place(node, b);
		if (place != NULL)
			move_upup->rb = place->index;
		(move_upup->pb) += 1;
	}
	cleanup_moves(move_upup);
}

void	ft_calcnodemap(t_mstck *node, t_mstck **b, size_t sizea)
{
	t_mstck	*max;
	t_mstck	*min;

	if (b != NULL)
	{
		if (node != NULL && *b != NULL)
		{
			max = ft_mstckmax(*b);
			min = ft_mstckmin(*b);
			calcmoves_upup(node, b, max, min);
			calcmoves_ud(node, b, max, min);
			calcmoves_ddown(node, b, max, sizea);
			calcmoves_du(node, b, max, sizea);
		}
	}
}

void	ft_calcmaps(t_mstck **a, t_mstck **b)
{
	t_mstck	*nodea;
	size_t	sizea;

	if (a != NULL && b != NULL)
	{
		if (*a != NULL && *b != NULL)
		{
			set_mapszero(a);
			nodea = *a;
			sizea = ft_mstcksize(*a);
			while (nodea)
			{
				ft_calcnodemap(nodea, b, sizea);
				nodea = nodea->next;
			}
		}
	}
}
