/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:52:52 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/20 10:35:16 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	test_char;

// 	test_char = '!';
// 	if (ft_isalnum(test_char))
// 		printf("'%c' est alphanumeric.\n", test_char);
// 	else
// 		printf("'%c' n'est pas alphanumeric.\n", test_char);
// 	return (0);
// }
