/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:03:26 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/28 10:43:48 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*chaine;

// 	chaine = "12345";
// 	printf("Chaine : '%s' \n", chaine);

// 	printf("Longueur : '%d' \n", ft_strlen(chaine));

// 	return (0);
// }
