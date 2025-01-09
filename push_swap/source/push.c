/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:13 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 11:32:59 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_lst **src, t_lst **dest)
{
		t_lst	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 2);
}

void	pb(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 2);
}
