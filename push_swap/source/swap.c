/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:08:33 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 13:53:07 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap(t_stacks *stacks, char stack_name)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	**stack;

	if (stack_name == 'a')
		stack = &stacks->p_a;
	else if (stack_name == 'b')
		stack = &stacks->p_b;
	else
		return ;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stacks *stacks)
{
	swap(stacks, 'a');
	ps_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(stacks, 'b');
	ps_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(stacks, 'a');
	swap(stacks, 'b');
	ps_putstr_fd("ss\n", 1);
}
