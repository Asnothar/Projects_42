/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:12:11 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 20:57:58 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	is_number(char *av)
{
	int	i;
	int	len;

	len = ps_strlen(av);
	if (!av)
		return (0);
	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	if (av[i] == '\0')
		return (0);
	while (av[i])
	{
		if (!ps_isdigit(av[i]))
			return (0);
		i++;
	}
	if (len > 11)
		return (0);
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
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	if (len_compare(s1, s2) != 0)
		return (len_compare(s1, s2));
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
	}
	return (0);
}

static int	has_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (j != i && number_compare(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]) || has_dup(av))
			return (1);
		i++;
	}
	return (0);
}
