/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:04 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/18 15:52:52 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static reverse_rotate(t_list **stack)
{
	t_list *first;
	t_list *last;

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

void	rra()
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 2);
}

void	rrb()
{
	reverse_rotate(stack b);
	ft_putstr_fd("rrb\n", 2);
}

void	rrr()
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 2);
}