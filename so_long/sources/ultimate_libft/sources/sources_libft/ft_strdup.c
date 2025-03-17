/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:13:50 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/20 10:37:23 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	char	*q;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	i++;
	new_str = (char *)malloc(i);
	if (new_str == NULL)
		return (NULL);
	q = new_str;
	while (*s != '\0')
	{
		*q = *s;
		q++;
		s++;
	}
	*q = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	const char *original = "Hello, world!";
// 	char *copy1, *copy2;

// 	copy1 = ft_strdup(original);
// 	copy2 = strdup(original);

// 	if (copy1 && copy2)
// 	{
// 		printf("Original : %s\n", original);
// 		printf("ft_strdup : %s\n", copy1);
// 		printf("strdup    : %s\n", copy2);

// 		if (strcmp(copy1, copy2) == 0)
// 			printf("Les deux copies sont identiques.\n");
// 		else
// 			printf("Les copies sont différentes \n");
// 		free(copy1);
// 		free(copy2);
// 	}
// 	return (0);
// }
