/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:37:36 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 14:49:14 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*append_line(char *map, char *line)
{
	char	*temp;

	temp = map;
	map = ft_strjoin(map, line);
	if (!map)
	{
		free(temp);
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	free(temp);
	return (map);
}

char	*read_map(int fd_map)
{
	char	*line;
	char	*map;

	line = get_next_line(fd_map);
	if (!line)
		return (ft_printf("Error: Map is empty\n"), NULL);
	map = ft_strdup("");
	if (!map)
		return (ft_printf(ERROR_ALLOC), NULL);
	while (line)
	{
		if (check_empty_line(line, 0))
		{
			free(line);
			free(map);
			ft_printf(ERROR_EMPTY_LINE);
			exit(EXIT_FAILURE);
		}
		map = append_line(map, line);
		free(line);
		line = get_next_line(fd_map);
	}
	return (map);
}

char	**get_map_str(char *filename, t_data *data)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: Map doesn't exist\n"), NULL);
	str = read_map(fd);
	close(fd);
	if (!validate_map(str, &map))
		return (NULL);
	get_map_dimensions(data, map);
	count_collectibles(data, map);
	return (map);
}

int	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return (EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (EXIT_FAILURE);
}

int	find_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
				return (EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (EXIT_FAILURE);
}
