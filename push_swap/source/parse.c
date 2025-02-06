/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:12:11 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 10:14:20 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	is_zero(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (str[i] == '\0');
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	len_compare(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	len1;
	int	len2;

	i = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	while (s1[i + len1])
		len1++;
	while (s2[j + len2])
		len2++;
	return (len1 - len2);
}

static int	number_compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
		i++;
	if (s2[j] == '+')
		j++;
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	if (len_compare(s1 + i, s2 + j) != 0)
		return (len_compare(s1 + i, s2 + j));
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
	}
	return (0);
}

int	has_dup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (number_compare(av[i], av[j]) == 0)
				return (1);
			if (is_zero(av[i]) && is_zero(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
