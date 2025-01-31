/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:25:17 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/29 12:05:26 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rev_rotate_both(t_stacks *stacks, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stacks);
	}
}

void	do_rotate_both(t_stacks *stacks, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(stacks);
	}
}

void	do_rotate_a(t_stacks *stacks, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stacks);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stacks);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_stacks *stacks, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stacks);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stacks);
			(*cost)++;
		}
	}
}

void	do_move(t_stacks *stacks, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stacks, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stacks, &cost_a, &cost_b);
	do_rotate_a(stacks, &cost_a);
	do_rotate_b(stacks, &cost_b);
	pa(stacks);
}
