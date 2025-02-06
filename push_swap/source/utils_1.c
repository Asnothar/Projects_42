/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:39:06 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:30:52 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_lst	*go_before_bottom(t_lst *pile)
{
	if (!pile || !pile->next)
		return (NULL);
	while (pile->next && pile->next->next)
		pile = pile->next;
	return (pile);
}

void	find_min_position(t_stacks *stacks, int *min_value, int *min_pos)
{
	t_lst	*current;
	int		pos;

	*min_value = stacks->p_a->content;
	*min_pos = 0;
	pos = 0;
	current = stacks->p_a;
	while (current)
	{
		if (current->content < *min_value)
		{
			*min_value = current->content;
			*min_pos = pos;
		}
		current = current->next;
		pos++;
	}
}

void	ps_lstadd_back(t_lst **lst, t_lst *new_elem)
{
	t_lst	*temp;

	if (*lst == NULL)
	{
		*lst = new_elem;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem;
}

int	av_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	exit_error(t_lst **p_a, t_lst **p_b, int i)
{
	t_lst	*temp;

	while (p_a && *p_a)
	{
		temp = *p_a;
		*p_a = (*p_a)->next;
		free(temp);
	}
	while (p_b && *p_b)
	{
		temp = *p_b;
		*p_b = (*p_b)->next;
		free(temp);
	}
	if (i == 1)
		write(2, "Error\n", 6);
	return (0);
}
