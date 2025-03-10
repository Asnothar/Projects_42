/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:37:36 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/10 10:52:09 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*read_map(int fd_map)
{
	char	*line;
	char	*temp;
	char	*map;

	line = get_next_line(fd_map);
	if (!line)
		exit_error("map is empty");
	map = ft_strdup("");
	while (line)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(temp);
		line = get_next_line(fd_map);
	}
	return (map);
}

void	get_map_dimensions(t_data *data, char **map)
{
	data->height = 0;
	data->width = 0;
	while (map[data->height])
	{
		int len = ft_strlen(map[data->height]);
		if (len > data->width)
			data->width = len;
		data->height++;
	}
}

char	**get_map_str(char *filename, t_data *data)
{
	int		fd_map;
	char	*str;
	char	**map;

	fd_map = open(filename, O_RDONLY);
	if (fd_map == -1)
		return (ft_printf("Error: map doesn't exist\n"), NULL);
	str = read_map(fd_map);
	close(fd_map);
	if (!str)
		return (ft_printf("Error: failed to read map\n"), NULL);
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		return (ft_printf("Error: map is not valid\n"), NULL);
	if (if_empty_line(map) == EXIT_FAILURE)
	{
		free_map(map);
		return (NULL);
	}
	if (is_map_rectangular(map) == EXIT_FAILURE)
	{
		free_map(map);
		return (NULL);
	}
	if (if_map_not_valid(map) == EXIT_FAILURE)
	{
		ft_printf("Error: map is not valid\n");
		free_map(map);
		return (NULL);
	}
	// Appel de la fonction pour calculer les dimensions
	get_map_dimensions(data, map);
	return (map);
}


int	parse_map(t_data *data, char *file)
{
	char	**map;

	map = get_map_str(file, data);
	if (!map)
		return (EXIT_FAILURE);
	if (if_map_not_valid(map))
		return (ft_printf("%s", "Map is not valid\n"), EXIT_FAILURE);
	data->map = map;
	return (EXIT_SUCCESS);
}
