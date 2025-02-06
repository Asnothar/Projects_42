/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:25:55 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:16 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	get_position(t_lst *stack)
{
	t_lst	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

int	get_lowest_index_position(t_stacks *stacks)
{
	t_lst	*tmp;
	int		lowest_value;
	int		lowest_pos;
	int		current_pos;

	tmp = stacks->p_a;
	lowest_value = INT_MAX;
	lowest_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->content < lowest_value)
		{
			lowest_value = tmp->content;
			lowest_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (lowest_pos);
}

int	get_target(t_stacks *stacks, int b_content)
{
	t_lst	*tmp;
	int		target_pos;
	int		closest_greater;

	tmp = stacks->p_a;
	target_pos = -1;
	closest_greater = INT_MAX;
	while (tmp)
	{
		if (tmp->content > b_content && tmp->content < closest_greater)
		{
			closest_greater = tmp->content;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_pos == -1)
		target_pos = get_lowest_index_position(stacks);
	return (target_pos);
}

void	get_target_position(t_stacks *stacks)
{
	t_lst	*tmp_b;

	tmp_b = stacks->p_b;
	get_position(stacks->p_a);
	get_position(stacks->p_b);
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(stacks, tmp_b->content);
		tmp_b = tmp_b->next;
	}
}
