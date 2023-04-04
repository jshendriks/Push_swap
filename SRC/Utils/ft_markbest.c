/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_markbest.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:31:01 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 16:55:32 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static size_t	find_leastmoves(t_mstck **a)
{
	t_mstck	*nodea;
	size_t	best;

	nodea = *a;
	best = ((nodea->map)->upup)->total;
	while (nodea)
	{
		if (((nodea->map)->upup)->total < best)
			best = ((nodea->map)->upup)->total;
		if (((nodea->map)->updown)->total < best)
			best = ((nodea->map)->updown)->total;
		if (((nodea->map)->downdown)->total < best)
			best = ((nodea->map)->downdown)->total;
		if (((nodea->map)->downup)->total < best)
			best = ((nodea->map)->downup)->total;
		nodea = nodea->next;
	}
	return (best);
}

static void	mark(t_mstck **a, size_t best)
{
	t_mstck	*nodea;

	nodea = *a;
	while (nodea)
	{
		if (((nodea->map)->upup)->total == best)
			nodea->mark = 1;
		else if (((nodea->map)->updown)->total == best)
			nodea->mark = 2;
		else if (((nodea->map)->downdown)->total == best)
			nodea->mark = 3;
		else if (((nodea->map)->downup)->total == best)
			nodea->mark = 4;
		if (nodea->mark != 0)
			nodea = NULL;
		else
			nodea = nodea->next;
	}
}

void	set_markszero(t_mstck **a)
{
	t_mstck	*nodea;

	nodea = *a;
	while (nodea)
	{
		nodea->mark = 0;
		nodea = nodea->next;
	}
}

void	ft_markbest(t_mstck **a)
{
	size_t	best;

	set_markszero(a);
	best = find_leastmoves(a);
	mark(a, best);
}
