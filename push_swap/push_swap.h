/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:02 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/19 09:50:40 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include "../../Cercle_1/libft/libft.h"

typedef struct	s_lst
{
	int				content;
	struct	s_lst	*next;
}	t_lst;

#endif