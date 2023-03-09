/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:03:34 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/09 18:05:56 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include <stdlib.h>

//STRUCT FOR DOUBLE LINKED LIST -----
typedef struct s_stack
{
	struct s_stack	*prev;
	size_t			index;
	int				content;
	int				iter_cnt;
	struct s_stack	*next;
}	t_stack;

# include "./Operations/operations.h"
# include "./Parsing/parsing.h"
# include "./Sorting/sorting.h"
# include "./Utils/utils.h"

#endif
