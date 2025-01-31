/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:30:36 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/29 10:00:01 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_save_three(t_stacks *stacks)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = stacks->size_a;
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if (stacks->p_a->content <= stack_size / 2)
		{
			pb(stacks);
			pushed++;
		}
		else
		{
			ra(stacks);
		}
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stacks);
		pushed++;
	}
}

int	is_sorted(t_lst *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	shift_stack(t_stacks *stacks)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stacks->size_a;
	lowest_pos = get_lowest_index_position(stacks);
	if (is_sorted(stacks->p_a))
		return ;
	else if (lowest_pos <= stack_size / 2)
	{
		while (lowest_pos > 0)
		{
			ra(stacks);
			lowest_pos--;
		}
	}
	else
	{
		while (lowest_pos < stack_size)
		{
			rra(stacks);
			lowest_pos++;
		}
	}
}

void	sort_full(t_stacks *stacks)
{
	if (is_sorted(stacks->p_a))
		return ;
	push_all_save_three(stacks);
	if (stacks->size_a <= 3)
		sort_small(stacks);
	if (!is_sorted(stacks->p_a))
		shift_stack(stacks);
	while (stacks->p_b)
	{
		get_target_position(stacks);
		get_cost(stacks);
		do_cheapest_move(stacks);
	}
}
