/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:55:39 by abeaufil          #+#    #+#             */
/*   Updated: 2024/10/30 20:43:54 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	test_char;

// 	test_char = '0';
// 	if (ft_isascii(test_char))
// 		printf("'%c' est ascii.\n", test_char);
// 	else
// 		printf("'%c' n'est pas ascii.\n", test_char);
// 	return (0);
// }
