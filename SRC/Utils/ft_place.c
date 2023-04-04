/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_place.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:41:11 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/04 17:14:07 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static t_mstck	*find_place(t_mstck *node, t_mstck **b)
{
	t_mstck	*nodeb;

	nodeb = *b;
	while (nodeb)
	{
		if (node->content < nodeb->content && nodeb->next)
		{
			if (node->content > (nodeb->next)->content)
				return (nodeb->next);
		}
		nodeb = nodeb->next;
	}
	return (NULL);
}

t_mstck	*ft_place(t_mstck *node, t_mstck **b)
{
	t_mstck	*nodeb;
	t_mstck	*last;

	if (b != NULL)
	{
		if (node != NULL && *b != NULL)
		{
			nodeb = *b;
			last = ft_mstcklast(*b);
			if (node->content > nodeb->content)
			{
				if (node->content < last->content)
					return (nodeb);
				else
					return (find_place(node, b));
			}
			else
				return (find_place(node, b));
		}
		return (NULL);
	}
	return (NULL);
}
