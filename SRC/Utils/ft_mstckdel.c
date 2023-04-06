/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mstckdel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 14:50:52 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/06 13:24:57 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

/*This file contains the functions:
			-ft_stackdelone(t_stack *stck)
			-ft_stackclear(t_stack **stck)
 *ft_stackdelone(t_stack *stck, void (*del)(void *)):
  		Since the content of the node stck was not allocated
		using malloc, this does not need to be freed.
		So, it only frees the node stck.
		If stck is NULL, the function does not do anything. 
 *ft_stackclear(t_stack **stck, void (*del)(void *)):
		Since the content of every node in stack does not need to be freed,
		only the nodes in the given stack need to be freed.
		If stck does not point to the beginning of stck,
		it sets the previous' nodes' next to NULL and 
		then deletes every node from stck to the end of the stack.
		It does this by iterating through the stack and 
		calling ft_stackdelone().
		It sets the content of stck to NULL.
		If *stck is NULL, the function does not do anything.
  */

void	ft_mstckdelone(t_mstck *stck)
{
	if (stck != NULL)
	{
		if (stck->map != NULL)
		{
			if ((stck->map)->upup != NULL)
				free((stck->map)->upup);
			if ((stck->map)->updown != NULL)
				free((stck->map)->updown);
			if ((stck->map)->downdown != NULL)
				free((stck->map)->downdown);
			if ((stck->map)->downup != NULL)
				free((stck->map)->downup);
			free(stck->map);
		}
		free(stck);
	}
}

void	ft_mstckclear(t_mstck **stck)
{
	t_mstck	*tmp_cur;
	t_mstck	*tmp_prv;

	if (stck != NULL)
	{
		if (*stck != NULL)
		{
			tmp_cur = *stck;
			if (tmp_cur->prev != NULL)
				(tmp_cur->prev)->next = NULL;
			tmp_prv = NULL;
			while (tmp_cur != NULL)
			{
				tmp_prv = tmp_cur;
				tmp_cur = tmp_cur->next;
				ft_mstckdelone(tmp_prv);
			}
			*stck = NULL;
		}
	}
}
