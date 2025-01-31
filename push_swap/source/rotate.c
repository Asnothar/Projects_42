/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:52:55 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 13:53:17 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rotate(t_stacks *stacks, char stack_name)
{
	t_lst	*first;
	t_lst	*last;
	t_lst	**stack;

	if (stack_name == 'a')
		stack = &stacks->p_a;
	else if (stack_name == 'b')
		stack = &stacks->p_b;
	else
		return ;
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stacks *stacks)
{
	rotate(stacks, 'a');
	ps_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks, 'b');
	ps_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks, 'a');
	rotate(stacks, 'b');
	ps_putstr_fd("rr\n", 1);
}
