/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:02 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/18 15:45:04 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
# include <stdarg.h>
# include "../../Cercle_1/libft/libft.h"

typedef struct	s_list
{
	int				content;
	struct	s_list	*next;
}	t_list;
