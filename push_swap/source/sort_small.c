/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:22:16 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:05 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

void	sort_smaller(t_stacks *stacks)
{
	t_lst	*top;
	t_lst	*bot;

	top = stacks->p_a;
	bot = top->next;
	if (top->content > bot->content)
		sa(stacks);
}

void	sort_small(t_stacks *stacks)
{
	int	top;
	int	mid;
	int	bot;

	top = stacks->p_a->content;
	mid = stacks->p_a->next->content;
	bot = stacks->p_a->next->next->content;
	if (top < mid && mid < bot)
		return ;
	if (top > mid && mid < bot && top < bot)
		sa(stacks);
	else if (top > mid && mid > bot)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stacks);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stacks);
}
