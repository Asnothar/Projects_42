/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:12:49 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/20 10:37:02 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dst;
	const unsigned char		*source;

	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (dst < source)
	{
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	else if (dst > source)
	{
		while (n > 0)
		{
			n--;
			dst[n] = source[n];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	source[] = "Bonjour";
// 	char	destination[20];

// 	printf("Source : %s\n", source);
// 	printf("Destination avant : %s\n", destination);

// 	ft_memmove(destination, source, strlen(source) + 1);
// 	memmove(destination, source, strlen(source) + 1);

// 	printf("Destination apres : %s\n", destination);

// 	return (0);
// }
