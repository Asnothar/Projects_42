/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:05:14 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/10 11:26:32 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("%s", ERROR_INIT_MLX);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int create_window(t_data *data)
{
	if (data->width <= 0 || data->height <= 0)
	{
		ft_printf("Dimensions de la carte invalides : width = %d, height = %d\n", data->width, data->height);
		return (EXIT_FAILURE);
	}

	data->win = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "So Long");
	if (!data->win)
	{
		ft_printf("%s", ERROR_WINDOW);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx); 
			free(data->mlx);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	put_texture(t_data *data, int x, int y, char c)
{
	int		s;
	void	*img;

	s = 64;
	img = NULL;
	if (!data || !data->mlx || !data->win)
		return ;
	if (c == '1')
		img = mlx_xpm_file_to_image(data->mlx, "wall.xpm", &s, &s);
	else if (c == '0')
		img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &s, &s);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(data->mlx, "collectible.xpm", &s, &s);
	else if (c == 'E' && data->collectibles == 0)
		img = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &s, &s);
	else if (c == 'E' && data->collectibles != 0)
		img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &s, &s);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(data->mlx, "player.xpm", &s, &s);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, img, x * 64, y * 64);
	mlx_destroy_image(data->mlx, img);
}

void draw_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			put_texture(data, j, i, data->map[i][j]);
			j++;
		}
		i++;
	}
}

