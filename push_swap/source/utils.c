/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:30:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 11:34:31 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst *go_bottom(t_lst *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_lst *go_before_bottom(t_lst *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_lst *create_node(int value)
{
    t_lst *new_node = (t_lst *)malloc(sizeof(t_lst));
    if (!new_node)
        return NULL;
    new_node->content = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(t_lst *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->content);
        stack = stack->next;
    }
    printf("NULL\n");
}

t_lst *new_node(int value)
{
    t_lst *node = (t_lst *)malloc(sizeof(t_lst));
    node->content = value;
    node->next = NULL;
    return node;
}

// Fonction pour afficher les éléments d'une pile
void print_stack(t_lst *stack)
{
	while (stack) {
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}
