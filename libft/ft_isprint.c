/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:01:07 by abeaufil          #+#    #+#             */
/*   Updated: 2024/10/30 20:43:43 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	test_char;

// 	test_char = '0';
// 	if (ft_isprint(test_char))
// 		printf("'%c' est printable.\n", test_char);
// 	else
// 		printf("'%c' n'est pas printable.\n", test_char);
// 	return (0);
// }
