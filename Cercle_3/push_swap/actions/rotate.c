/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:52:55 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/18 15:09:06 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void rotate(t_list **stack)
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

void	ra(stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 2);
	
}

void	rb(stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 2);
}

void	rr(stack_a, stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 2);
}