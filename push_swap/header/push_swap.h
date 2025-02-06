/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:02 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:31:17 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_lst
{
	int				content;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stacks
{
	t_lst	*p_a;
	t_lst	*p_b;
	int		size_a;
	int		size_b;
}	t_stacks;

//	Utils
t_lst		*go_before_bottom(t_lst *pile);
void		find_min_position(t_stacks *stacks, int *min_value, int *min_pos);
void		rotate_to_min(t_stacks *stacks);
void		ps_lstadd_back(t_lst **lst, t_lst *new_elem);
int			av_len(char **args);
void		ps_lstdelone(t_lst *lst);
void		ps_lstclear(t_lst **lst);
void		free_values(char **values);
void		free_stacks(t_stacks *stacks);
int			exit_error(t_lst **p_a, t_lst **p_b, int i);
int			ps_strlen(char *str);
long int	ps_atoi(const char *str);
void		ps_putstr_fd(char *s, int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ps_strcat(char *dest, char *src);
char		**ps_split(char *s, char c);
void		free_args(char **args);

//	Operations
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

//	Initializing
t_stacks	*init_stacks(void);
t_stacks	*fill_stack_values(int ac, char **av);

//	Parsing
int			is_number(const char *str);
int			has_dup(char **av);

//	Sorting < 3
void		sort_smaller(t_stacks *stacks);
void		sort_small(t_stacks *stacks);

// 	Sorting Full
void		do_rev_rotate_both(t_stacks *stacks, int *cost_a, int *cost_b);
void		do_rotate_both(t_stacks *stacks, int *cost_a, int *cost_b);
void		do_rotate_a(t_stacks *stacks, int *cost);
void		do_rotate_b(t_stacks *stacks, int *cost);
void		do_move(t_stacks *stacks, int cost_a, int cost_b);
int			ft_abs(int n);
void		get_cost(t_stacks *stacks);
void		do_cheapest_move(t_stacks *stacks);
void		get_position(t_lst *stack);
int			get_lowest_index_position(t_stacks *stacks);
int			get_target(t_stacks *stacks, int b_content);
void		get_target_position(t_stacks *stacks);
int			is_sorted(t_lst *stack);
void		rotate_to_min(t_stacks *stacks);
void		sort_full(t_stacks *stacks);

//	Main
int			main(int argc, char **argv);

#endif
