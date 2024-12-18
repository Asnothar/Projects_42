/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:34 by abeaufil          #+#    #+#             */
/*   Updated: 2024/10/30 20:51:58 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	ft_toupper_bis(unsigned int i, char c)
{
	i = 32;
	if (c >= 'a' && c <= 'z')
		return (c - i);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	size_t			len;
	char			*result;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char	*original = "hello world";
// 	char		*result;

// 	result = ft_strmapi(original, ft_toupper_bis);
// 	if (result == NULL)
// 	{
// 		printf("Erreur d'allocation\n");
// 		return (1);
// 	}
// 	printf("originale : %s\n", original);
// 	printf("transformee : %s\n", result);
// 	free(result);
// 	return (0);
// }