/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:52:55 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/19 10:58:22 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

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

t_lst *new_node(int value)
{
    t_lst *node = (t_lst *)malloc(sizeof(t_lst));
    node->content = value;
    node->next = NULL;
    return node;
}

// Fonction pour afficher les éléments d'une pile
void print_stack(t_lst *stack) {
	while (stack) {
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}

int main()
{
	// Création de la pile A
	t_lst *stack_a = new_node(1);
	stack_a->next = new_node(2);
	stack_a->next->next = new_node(3);

	// Création de la pile B
	t_lst *stack_b = new_node(4);
	stack_b->next = new_node(5);
	stack_b->next->next = new_node(6);

	printf("Pile A avant rotation:\n");
	print_stack(stack_a);
	printf("Pile B avant rotation:\n");
	print_stack(stack_b);

	// Tester ra
	printf("\nAppel à ra:\n");
	ra(&stack_a);
	print_stack(stack_a);

	// Tester rb
	printf("\nAppel à rb:\n");
	rb(&stack_b);
	print_stack(stack_b);

	// Tester rr
	printf("\nAppel à rr:\n");
	rr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);

	return 0;
}