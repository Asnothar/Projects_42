/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:19:57 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 14:25:41 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**duplicate_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **tab, t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	flood_fill(tab, data, x, y - 1);
	flood_fill(tab, data, x, y + 1);
	flood_fill(tab, data, x - 1, y);
	flood_fill(tab, data, x + 1, y);
}

int	is_map_solvable(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_map_valid(t_data *data)
{
	char	**copy;

	copy = duplicate_map(data->map, data->height);
	if (!copy)
		return (0);
	flood_fill(copy, data, data->player_x, data->player_y);
	if (!is_map_solvable(copy, data->width, data->height))
	{
		free_tab_char(copy);
		free_tab_char(data->map);
		ft_printf(ERROR_FINISH);
		return (EXIT_SUCCESS);
	}
	free_tab_char(copy);
	return (1);
}
