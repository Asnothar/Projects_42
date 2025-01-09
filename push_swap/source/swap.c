/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:08:33 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 11:32:02 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_lst **stack)
{
    t_lst *first;
    t_lst *second;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void	sa(t_lst **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 2);
}

void	sb(t_lst **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 2);
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 2);
}
