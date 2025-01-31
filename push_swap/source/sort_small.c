/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:22:16 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/28 17:55:47 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
