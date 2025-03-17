/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:56 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/20 10:37:49 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	size_t	size = 6;
// 	char	s1[] = "abaaz";
// 	char	s2[] = "aaaaa";

// 	printf("Vraie fonction : %d\n", strncmp(s1, s2, size));
// 	printf("Ma fonction : %d\n\n", ft_strncmp(s1, s2, size));
// 	return (0);
// }
