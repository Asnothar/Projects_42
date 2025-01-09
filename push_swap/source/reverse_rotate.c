/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:04 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 11:35:18 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_lst **stack)
{
	t_lst *last;
	t_lst *b_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	last = go_bottom(*stack);
	b_last = go_before_bottom(*stack);
	if (b_last)
		b_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_lst **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 2);
}

void	rrb(t_lst **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 2);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 2);
}

// int main(void)
// {
//     t_lst *stack_a = create_node(1);
//     stack_a->next = create_node(2);
//     stack_a->next->next = create_node(3);
//     stack_a->next->next->next = create_node(4);

//     t_lst *stack_b = create_node(5);
//     stack_b->next = create_node(6);
//     stack_b->next->next = create_node(7);

//     printf("Liste A avant rra : ");
//     print_list(stack_a);

//     printf("Liste B avant rrb : ");
//     print_list(stack_b);

//     rra(&stack_a);
//     printf("Liste A après rra : ");
//     print_list(stack_a);

//     rrb(&stack_b);
//     printf("Liste B après rrb : ");
//     print_list(stack_b);

//     rrr(&stack_a, &stack_b);
//     printf("Liste A après rrr : ");
//     print_list(stack_a);

//     printf("Liste B après rrr : ");
//     print_list(stack_b);

//     while (stack_a)
//     {
//         t_lst *tmp = stack_a;
//         stack_a = stack_a->next;
//         free(tmp);
//     }
//     while (stack_b)
//     {
//         t_lst *tmp = stack_b;
//         stack_b = stack_b->next;
//         free(tmp);
//     }

//     return 0;
// }