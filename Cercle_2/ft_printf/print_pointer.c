/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:37 by abeaufil          #+#    #+#             */
/*   Updated: 2024/11/13 18:51:02 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long ptr)
{
	const char	*hex_chars;
	char		buffer[16];
	int			i;
	int			len;

	i = 0;
	len = 2;
	hex_chars = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (ptr == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	while (ptr > 0)
	{
		buffer[i++] = hex_chars[ptr % 16];
		ptr /= 16;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		len++;
	}
	return (len);
}
