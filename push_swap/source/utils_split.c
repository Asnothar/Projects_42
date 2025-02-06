/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:18:37 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/06 08:35:44 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static char	*copy_str(char *s, int start, int end)
{
	return (ft_substr(s, start, (end - start)));
}

static void	free_tab(char **tab, int y)
{
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

static int	ft_copy_str_tab(char **tab, char *s, char c, int start)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			tab[y] = copy_str(s, start, i);
			if (!tab[y])
				return (free_tab(tab, y - 1), 0);
			y++;
		}
	}
	tab[y] = NULL;
	return (1);
}

char	**ps_split(char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_copy_str_tab(tab, s, c, 0))
		return (NULL);
	return (tab);
}
