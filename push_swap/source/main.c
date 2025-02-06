/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:48:09 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:16 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*new_stacks;

	new_stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new_stacks)
		return (NULL);
	new_stacks->p_a = NULL;
	new_stacks->p_b = NULL;
	new_stacks->size_a = 0;
	new_stacks->size_b = 0;
	return (new_stacks);
}

static void	push_swap(t_stacks *stacks)
{
	if (!is_sorted(stacks->p_a) || stacks->size_b > 0)
	{
		if (stacks->size_a == 2)
			sort_smaller(stacks);
		else if (stacks->size_a == 3)
			sort_small(stacks);
		else if (stacks->size_a > 3)
			sort_full(stacks);
	}
}

static char	**split_arguments(int argc, char **argv, int i)
{
	char	*combined_args;
	int		total_len;
	char	**result;

	i = 1;
	total_len = 0;
	while (i < argc)
	{
		total_len += ps_strlen(argv[i]) + 1;
		i++;
	}
	combined_args = (char *)malloc(total_len + 1);
	if (!combined_args)
		return (NULL);
	combined_args[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ps_strcat(combined_args, argv[i]);
		if (i < argc - 1)
			ps_strcat(combined_args, " ");
		i++;
	}
	result = ps_split(combined_args, ' ');
	return (free(combined_args), result);
}

int	is_correct_input(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (!av)
			return (1);
		while (av[i] != NULL)
		{
			if (!is_number(av[i]) || has_dup(av))
				return (1);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			if_error;
	char		**args;
	int			i;

	i = 0;
	args = split_arguments(argc, argv, i);
	if_error = is_correct_input(args);
	if (if_error == 1)
		return ((free_args(args)), exit_error(NULL, NULL, 1));
	stacks = fill_stack_values(av_len(args), args);
	free_args(args);
	if (!stacks)
		return (exit_error(NULL, NULL, 1));
	if (stacks->size_a < 1)
	{
		exit_error(&stacks->p_a, &stacks->p_b, 0);
		free(stacks);
		return (0);
	}
	push_swap(stacks);
	if (!is_sorted(stacks->p_a))
		rotate_to_min(stacks);
	return ((exit_error(&stacks->p_a, &stacks->p_b, 0)), (free(stacks)), 0);
}
