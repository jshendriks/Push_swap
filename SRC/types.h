/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 17:36:47 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/28 14:26:20 by jhendrik      ########   odam.nl         */
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

typedef struct s_moves
{
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	total;
}	t_moves;

typedef struct s_map
{
	t_moves	*upup;
	t_moves	*updown;
	t_moves	*downdown;
	t_moves	*downup;
}	t_map;
/*upup: use rotate_a and rotate_b
 * updown: use rotate_a and rrotate_b
 * downdown: use rrotate_a and rrotate_b
 * downup: use rrotate_a and rotate_b */
typedef struct s_mstck
{
	struct s_mstck	*prev;
	size_t			index;
	int				content;
	t_map			*map;
	int				mark;
	struct s_mstck	*next;
}	t_mstck;

#endif
