/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 17:36:47 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 17:47:27 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	size_t			index;
	int				content;
	int				iter_cnt;
	struct s_stack	*next;
}	t_stack;

typedef void	(*t_stckfnc)(t_stack **a, t_stack **b);

#endif
