/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mm.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 12:20:21 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/20 12:24:52 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_stack	*ft_max(t_stack *head)
{
	t_stack	*node;
	t_stack	*max;

	max = NULL;
	if (head != NULL)
	{
		node = head;
		max = head;
		while (node != NULL)
		{
			if (node->content > max->content)
				max = node;
			node = node->next;
		}
		return (max->content);
	}
	return (max);
}

t_stack	*ft_min(t_stack *head)
{
	t_stack	*node;
	t_stack	*min;

	min = NULL;
	if (head != NULL)
	{
		node = head;
		min = head;
		while (node != NULL)
		{
			if (node->content < min->content)
				min = node;
			node = node->next;
		}
		return (min->content);
	}
	return (min);
}
