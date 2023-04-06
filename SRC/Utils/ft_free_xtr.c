/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_xtr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:37:37 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 12:07:51 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "./../src.h"

/*This file contains the function ft_free_double(char **ptr_subs)
 * ft_free_double(char **ptr_subs):
		This function frees the entries in the double pointer
		by iterating through the double pointer.
		Then it frees the double pointer.
		This function will loop infinitely if ptr_subs[k]
		is not NULL for some k.
 */

void	ft_free_double(char **ptr_subs)
{
	int	k;

	k = 0;
	while (ptr_subs[k] != NULL)
	{
		free(ptr_subs[k]);
		k++;
	}
	free(ptr_subs);
}
