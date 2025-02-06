/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:36:46 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:29 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_stacks	*init_and_check_stacks(void)
{
	t_stacks	*stacks;

	stacks = init_stacks();
	if (!stacks)
		return (NULL);
	return (stacks);
}

static int	process_value(char *value, t_stacks *stacks)
{
	t_lst		*new_elem;
	long int	nb;

	nb = ps_atoi(value);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	new_elem = (t_lst *)malloc(sizeof(t_lst));
	if (!new_elem)
		return (0);
	new_elem->content = (int)nb;
	new_elem->next = NULL;
	ps_lstadd_back(&stacks->p_a, new_elem);
	stacks->size_a++;
	return (1);
}

static int	process_values(char **values, t_stacks *stacks)
{
	int	j;

	j = 0;
	while (values[j])
	{
		if (!process_value(values[j], stacks))
		{
			free_values(values);
			free_stacks(stacks);
			return (0);
		}
		j++;
	}
	free_values(values);
	return (1);
}

static int	fill_stack_from_argument(char *arg, t_stacks *stacks)
{
	char	**values;

	values = ps_split(arg, ' ');
	if (!values)
	{
		free_stacks(stacks);
		return (0);
	}
	if (!process_values(values, stacks))
		return (0);
	return (1);
}

t_stacks	*fill_stack_values(int ac, char **av)
{
	t_stacks	*stacks;
	int			i;

	i = 0;
	stacks = init_and_check_stacks();
	if (!stacks)
		return (NULL);
	while (i < ac)
	{
		if (!fill_stack_from_argument(av[i], stacks))
			return (NULL);
		i++;
	}
	return (stacks);
}
