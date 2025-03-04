/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/04 19:24:58 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_data	*parse_map(const char *filename)
{
	int		fd;
	char	*line;
	t_data	*data;
	char	**new_map;

	if (strlen(filename) < 4 || strcmp(filename + strlen(filename) - 4, ".ber") != 0)
		return (ft_printf("%s", ERROR_BER), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s", ERROR_OPEN), NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (close(fd), NULL);
	data->height = 0;
	data->width = 0;
	data->map = (NULL);
	while ((line = get_next_line(fd)))
	{
		if (data->width == 0)
		{
			data->width = ft_strlen(line) - 1;
			printf("Première ligne, longueur : %d\n", data->width);
		}
		else if (data->width != (int)ft_strlen(line) - 1)
		{
			printf("Longueur attendue : %d,\n Longueur : %d\n", data->width, (int)ft_strlen(line) - 1);
			free(line);
			while (data->height > 0)
			{
				free(data->map[data->height - 1]);
				data->height--;
			}
			free(data->map);
			close(fd);
			free(data);
			return (NULL);
		}
		new_map = malloc(sizeof(char *) * (data->height + 1));
		if (!new_map)
		{
			free(line);
			while (data->height > 0)
			{
				free(data->map[data->height - 1]);
				data->height--;
			}
			free(data->map);
			close(fd);
			free(data);
			return (NULL);
		}
		int i = 0;
		while (i < data->height)
		{
			new_map[i] = data->map[i];
			i++;
		}
		free(data->map);
		new_map[data->height] = line;
		data->map = new_map;
		data->height++;
	}
	close(fd);
	return (data);
}

int parse_map_wrapper(const char *filename, t_data **data)
{
	*data = parse_map(filename);
	if (*data)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
