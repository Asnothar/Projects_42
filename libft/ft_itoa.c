/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:41:10 by abeaufil          #+#    #+#             */
/*   Updated: 2024/10/31 17:07:44 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nbr)
{
	long	cpy;
	int		count;

	count = 1;
	cpy = nbr;
	if (cpy < 0)
	{
		cpy = -cpy;
		count++;
	}
	while (cpy > 9)
	{
		cpy /= 10;
		count++;
	}
	return (count);
}

void	_ft_itoa(long n, int size, char *result)
{
	if (n < 0)
	{
		n = -n;
		*result++ = '-';
		size--;
	}
	result[size] = '\0';
	while (size--)
	{
		result[size] = '0' + n % 10;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	i = int_len(n);
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	_ft_itoa(n, i, result);
	return (result);
}
// int main()
// {
// 	printf("%s\n", ft_itoa(-0));
// }