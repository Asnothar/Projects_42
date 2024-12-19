/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:57 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/18 15:41:59 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../Cercle_1/libft/libft.h"

int		ft_printf(const char *input, ...);
int		print_int(int n);
int		print_char(char c);
int		print_string(char *s);
int		print_pointer(unsigned long value);
int		print_unsigned(unsigned int nb);
int		print_hex(unsigned int value, int asc);

#endif
