/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:39:32 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/04/03 17:22:02 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "./../types.h"
# include "./../Operations/operations.h"

//FUNCTION TO MAKE STACK-----------
t_stack	*ft_makestack_int(int argc, char *argv[]);
/*This function returns a stack filled with the given arguments.
  The input must be correct according to the check functions.*/
t_mstck	*ft_makemstck_int(int argc, char *argv[]);
/*...*/

//FUNCTIONS TO FREE ----------------
void	ft_free_double(char **ptr_subs);
/*This function frees the entries in the double pointer, 
  then it frees the double pointer.
  If ptr_subs[k] is not NULL for the last k, 
  this function will loop infinitely.*/

//TO CHECK IF STACK SORTED -----------
int		issorted_asc(t_stack *a);
/*This function iterates through the given stack
  and checks whether the stack is sorted in ascending
  order.
  If it is sorted it returns -1.
  Otherwise it returns the index of the node
  where the ascending order is interupted.
  If a is NULL, it returns -2.*/
int		issorted_des(t_stack *a);
/*This function iterates through the given stack
  and checks whether the stack is sorted in descending
  order.
  If it is sorted it returns -1.
  Otherwise it returns the index of the node
  where the descending order is interupted.
  If a is NULL, it returns -2.*/

//FUNCTIONS FOR DOUBLE LINKED LIST TYPE T_STACK --
t_stack	*ft_stacknew(int content);
/*Allocates (using malloc) a new node with the given content
  and returns this node. If the malloc fails it returns NULL.*/
t_stack	*ft_stacklast(t_stack *stck);
/*This function returns the last node of the stack stck.
  If stck is NULL, it returns NULL.*/
t_stack	*ft_stackfirst(t_stack *stck);
/*This function returns the first node of the stack stck.
  If stck is NULL, it returns NULL.*/
size_t	ft_stacksize(t_stack *stck);
/*This function returns the amount of nodes the stack stck
 * consists of.*/
void	ft_indexing(t_stack *stck);
/*This function re-indexes the given stack.*/
void	ft_stackadd_front(t_stack **stck, t_stack *new);
/*This function adds the node new to the front of stck.
  If the stack stck is NULL, the node new becomes the stack.*/
void	ft_stackadd_back(t_stack **stck, t_stack *new);
/*This function adds the node new to the back of stck.
  If the stack stck is NULL, the node new becomes the stack.*/
void	ft_stackdelone(t_stack *stck);
/*Since the content of stck was not allocated using malloc,
  it only needs to free the node stck.*/
void	ft_stackclear(t_stack **stck);
/*This function clears the stack stck.
  Once the stack is cleared, *stck is set to NULL.
  If *stck does not point to the first node of the stack,
  the previous node is set to be the last.*/

//FUNCTIONS FOR DOUBLE LINKED LIST TYPE T_MSTCK --
t_mstck	*ft_mstcknew(int content);
/*...*/
t_mstck	*ft_mstcklast(t_mstck *stck);
/*...*/
t_mstck	*ft_mstckfirst(t_mstck *stck);
/*...*/
size_t	ft_mstcksize(t_mstck *stck);
/*...*/
void	ft_mstck_indexing(t_mstck *stck);
/*...*/
void	ft_mstckadd_front(t_mstck **stck, t_mstck *new);
/*...*/
void	ft_mstckadd_back(t_mstck **stck, t_mstck *new);
/*...*/
void	ft_mstckdelone(t_mstck *stck);
/*...*/
void	ft_mstckclear(t_mstck **stck);
/*...*/

//FUNCTIONS FOR DETERMINING MAX/MIN IN STACK -------
t_stack	*ft_max(t_stack *head);
/*Returns the node in the given stack which contains the biggest
 * integer*/
t_stack	*ft_min(t_stack *head);
/*Returns the node in the given stack which contains the smallest
 * integer*/
t_mstck	*ft_mstckmax(t_mstck *head);
/*...*/
t_mstck	*ft_mstckmin(t_mstck *head);
/*...*/

//FUNCTIONS TO DETERMINE LEAST POSSIBLE MOVES -----
t_mstck	*ft_place(t_mstck *node, t_mstck **b);
/*...*/
t_mstck	*ft_place_asc(t_mstck *node, t_mstck **a);
/*...*/

//FUNCTIONS FOR MAPS ----------------------------
void	set_mapszero(t_mstck **a);
/*...*/
void	cleanup_moves(t_moves *move);
/*...*/
void	calcmoves_upup(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min);
/*...*/
void	calcmoves_updown(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min);
/*...*/
void	calcmoves_downdown(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min, size_t sizea);
/*...*/
void	calcmoves_downup(t_mstck *node, t_mstck **b, t_mstck *max, t_mstck *min, size_t sizea);
/*...*/
void	ft_calcnodemap(t_mstck *node, t_mstck **b, size_t sizea);
/*...*/
void	ft_calcmaps(t_mstck **a, t_mstck **b);
/*...*/
void	set_markszero(t_mstck **a);
/*...*/
void	ft_markbest(t_mstck **a);
/*...*/

//FUNCTION TO MERGE TWO SORTED STACKS ------------
void	merge(t_stack **a, t_stack **b, size_t n);

//EXECUTE MAP MSTCK -----------------------------
void	exec_best(t_mstck **a, t_mstck **b);
/*...*/
#endif
