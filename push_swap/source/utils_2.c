/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:09:20 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:45 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_lstdelone(t_lst *lst)
{
	if (lst)
		free(lst);
}

void	ps_lstclear(t_lst **lst)
{
	t_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ps_lstdelone(*lst);
		*lst = tmp;
	}
}

void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
}

void	free_stacks(t_stacks *stacks)
{
	ps_lstclear(&stacks->p_a);
	ps_lstclear(&stacks->p_b);
	free(stacks);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
