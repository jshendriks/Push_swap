/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrr_ntimes_mstck.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 15:08:15 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 15:10:58 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"

void	rotate_ab_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rotate_ab_mstck(a, b);
			i++;
		}
	}
}

void	rrotate_ab_ntimes_mstck(t_mstck **a, t_mstck **b, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rrotate_ab_mstck(a, b);
			i++;
		}
	}
}
