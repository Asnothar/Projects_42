/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:54 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 13:47:18 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	get_cost(t_stacks *stacks)
{
	t_lst	*tmp_b;

	tmp_b = stacks->p_b;
	while (tmp_b)
	{
		if (tmp_b->pos > stacks->size_b / 2)
			tmp_b->cost_b = (stacks->size_b - tmp_b->pos) * -1;
		else
			tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->target_pos > stacks->size_a / 2)
			tmp_b->cost_a = (stacks->size_a - tmp_b->target_pos) * -1;
		else
			tmp_b->cost_a = tmp_b->target_pos;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stacks *stacks)
{
	t_lst	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	tmp = stacks->p_b;
	cheapest = INT_MAX;
	cost_a = 0;
	cost_b = 0;
	while (tmp)
	{
		total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stacks, cost_a, cost_b);
}
