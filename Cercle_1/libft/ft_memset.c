/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:22:07 by abeaufil          #+#    #+#             */
/*   Updated: 2024/10/30 20:48:17 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return ((void *) str);
}

// int	main(void)
// {
// 	char	buffer[10];

// 	printf ("%p\n", (char *)ft_memset (buffer, 'A', 9));
// 	ft_memset(buffer, 'A', 9);
// 	printf("%s\n", buffer);
// 	return (0);
// }
