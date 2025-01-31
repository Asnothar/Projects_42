/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:13 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 13:53:23 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	push(t_stacks *stacks, char to_stack)
{
	t_lst	**src;
	t_lst	**dest;
	t_lst	*tmp;

	if (to_stack == 'a')
	{
		src = &stacks->p_b;
		dest = &stacks->p_a;
		stacks->size_b--;
		stacks->size_a++;
	}
	else if (to_stack == 'b')
	{
		src = &stacks->p_a;
		dest = &stacks->p_b;
		stacks->size_a--;
		stacks->size_b++;
	}
	else
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_stacks *stacks)
{
	push(stacks, 'a');
	ps_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	push(stacks, 'b');
	ps_putstr_fd("pb\n", 1);
}
