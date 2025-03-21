/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:30:22 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 11:07:11 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	get_map_dimensions(t_data *data, char **map)
{
	int	len;

	data->height = 0;
	data->width = 0;
	while (map[data->height])
	{
		len = ft_strlen(map[data->height]);
		if (len > data->width)
			data->width = len;
		data->height++;
	}
}

void	count_collectibles(t_data *data, char **map)
{
	int	i;
	int	j;

	data->collectibles = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				data->collectibles++;
			j++;
		}
		i++;
	}
}

int	validate_map(char *str, char ***map)
{
	if (!str || check_quantities(str) == EXIT_FAILURE)
		return (free(str), 0);
	*map = ft_split(str, '\n');
	free(str);
	if (!*map || check_lines(*map) == EXIT_FAILURE
		|| check_rectangular(*map) == EXIT_FAILURE)
		return (free_tab_char(*map), 0);
	return (1);
}

int	parse_map(t_data *data, char *file)
{
	data->map = get_map_str(file, data);
	if (!data->map)
		return (EXIT_FAILURE);
	if (is_map_enclosed(data) == EXIT_FAILURE)
		return (printf(ERROR_ENCLOSED), EXIT_FAILURE);
	data->player_x = -1;
	data->player_y = -1;
	if (find_player(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (find_exit(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!check_flood_fill(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
