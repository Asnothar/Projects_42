/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:52:55 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 09:43:57 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_lst **stack)
{
	t_lst *first;
	t_lst *last;

	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;

	last = *stack;
	while (last->next)
		last = last->next;

	last->next = first;
}

void	ra(t_lst **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 2);
}

void	rb(t_lst **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 2);
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 2);
}
