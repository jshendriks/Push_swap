/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_mapszero.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:56:52 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:57:20 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static void	set_moveszero(t_moves *move)
{
	if (move != NULL)
	{	
		move->ra = 0;
		move->rb = 0;
		move->rr = 0;
		move->rra = 0;
		move->rrb = 0;
		move->rrr = 0;
		move->sa = 0;
		move->sb = 0;
		move->ss = 0;
		move->pa = 0;
		move->pb = 0;
		move->total = 0;
	}
}

void	set_mapszero(t_mstck **a)
{
	t_mstck	*node;

	if (a != NULL)
	{
		if (*a != NULL)
		{
			node = *a;
			while (node)
			{
				set_moveszero(((node->map)->upup));
				set_moveszero((node->map)->updown);
				set_moveszero((node->map)->downdown);
				set_moveszero((node->map)->downup);
				node = node->next;
			}
		}
	}
}
