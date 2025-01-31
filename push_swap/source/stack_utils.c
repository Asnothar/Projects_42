/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:39:06 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 14:50:25 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_lst	*go_bottom(t_lst *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}

t_lst	*go_before_bottom(t_lst *pile)
{
	if (!pile || !pile->next)
		return (NULL);
	while (pile->next && pile->next->next)
		pile = pile->next;
	return (pile);
}

static void	find_min_position(t_stacks *stacks, int *min_value, int *min_pos)
{
	t_lst	*current;
	int		pos;

	*min_value = stacks->p_a->content;
	*min_pos = 0;
	pos = 0;
	current = stacks->p_a;
	while (current)
	{
		if (current->content < *min_value)
		{
			*min_value = current->content;
			*min_pos = pos;
		}
		current = current->next;
		pos++;
	}
}

void	rotate_to_min(t_stacks *stacks)
{
	int	min_value;
	int	min_pos;

	if (!stacks->p_a || stacks->size_a <= 1)
		return ;
	find_min_position(stacks, &min_value, &min_pos);
	if (min_pos == 0)
		return ;
	if (min_pos > stacks->size_a / 2)
	{
		while (stacks->p_a->content != min_value)
			rra(stacks);
	}
	else
	{
		while (stacks->p_a->content != min_value)
			ra(stacks);
	}
}
