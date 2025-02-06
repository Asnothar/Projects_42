/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:04 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 09:05:36 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_lst	*go_bottom(t_lst *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}

static void	reverse_rotate(t_stacks *stacks, char stack_name)
{
	t_lst	*last;
	t_lst	*before_last;
	t_lst	**stack;

	if (stack_name == 'a')
		stack = &stacks->p_a;
	else if (stack_name == 'b')
		stack = &stacks->p_b;
	else
		return ;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = go_bottom(*stack);
	before_last = go_before_bottom(*stack);
	if (before_last)
		before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(stacks, 'a');
	ps_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(stacks, 'b');
	ps_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(stacks, 'a');
	reverse_rotate(stacks, 'b');
	ps_putstr_fd("rrr\n", 1);
}
