/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:02 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/06 16:01:37 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include "../../../Cercle_1/libft/libft.h"

typedef struct	s_lst
{
	int				content;
	struct	s_lst	*next;
}	t_lst;

typedef struct	s_stacks
{
	t_lst	p_a;		// Appel de la pile A
	t_lst	p_b;		// Appel de la pile B
	int		size_a;		// Taille A
	int		size_b;		// Taille B
	int		index;
}	t_stacks;

t_lst		*go_bottom(t_lst *stack);
t_lst 		*go_before_bottom(t_lst *stack);
t_lst 		*create_node(int value);
void 		print_list(t_lst *stack);
t_lst 		*new_node(int value);
void 		print_stack(t_lst *stack);
#endif



// faire une fonction qui trie A quand il y a que trois nombre (mettre le max au bottom et si le rang > au 2 swap)
// deux push B en debut (unique si apres le premier push B il y a plus 3 nombre dans A)
// il faut calculer les couts pour mettre le nomber au dessus de son entier inferieur le plus proche attention s'il n'existe pas c'est que le nombre est le nouveau min de B donc le mettre au dessus du max de B
// trier decroissant sur b 