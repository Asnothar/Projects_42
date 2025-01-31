/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:48:09 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 14:02:40 by abeaufil         ###   ########.fr       */
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
	return (1);
}

static t_stacks	*fill_stack_values(int ac, char **av)
{
	t_stacks	*stacks;
	t_lst		*new_elem;
	long int	nb;
	int			i;

	stacks = init_stacks();
	if (!stacks)
		exit_error(&stacks->p_a, &stacks->p_b, 1);
	i = 1;
	while (i < ac)
	{
		nb = ps_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stacks->p_a, &stacks->p_b, 1);
		new_elem = (t_lst *)malloc(sizeof(t_lst));
		if (!new_elem)
			exit_error(&stacks->p_a, &stacks->p_b, 1);
		new_elem->content = (int)nb;
		new_elem->next = NULL;
		ps_lstadd_back(&stacks->p_a, new_elem);
		stacks->size_a++;
		i++;
	}
	return (stacks);
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

// void	print_piles(t_stacks *piles)
// {
// 	t_lst	*l;

// 	l = piles->p_a;
// 	printf("\tpile a : ");
// 	while (l != NULL)
// 	{
// 		printf("%d ", l->content);
// 		l = l->next;
// 	}
// 	printf("\n\tpile b : ");
// 	l = piles->p_b;
// 	while (l != NULL)
// 	{
// 		printf("%d ", l->content);
// 		l = l->next;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
		exit_error(NULL, NULL, 1);
	stacks = fill_stack_values(argc, argv);
	if (!stacks)
		exit_error(NULL, NULL, 1);
	push_swap(stacks);
	if (!is_sorted(stacks->p_a))
		rotate_to_min(stacks);
	exit_error(&stacks->p_a, &stacks->p_b, 0);
	free(stacks);
	return (0);
}
