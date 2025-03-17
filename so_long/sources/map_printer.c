/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:05:14 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 16:02:02 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf(ERROR_INIT_MLX);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	create_window(t_data *data)
{
	int	p_width;
	int	p_height;

	p_width = data->width * 64;
	p_height = data->height * 64;
	if (data->width <= 0 || data->height <= 0)
		return (ft_printf(ERROR_DIMENSION), EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, p_width, p_height, "So Long");
	if (!data->win)
	{
		ft_printf(ERROR_WINDOW);
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
		img = mlx_xpm_file_to_image(data->mlx, "./skin/wall.xpm", &s, &s);
	else if (c == '0')
		img = mlx_xpm_file_to_image(data->mlx, "./skin/floor.xpm", &s, &s);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(data->mlx, "./skin/loot.xpm", &s, &s);
	else if (c == 'E' && data->collectibles != 0)
		img = mlx_xpm_file_to_image(data->mlx, "./skin/exit.xpm", &s, &s);
	else if (c == 'E' && data->collectibles == 0)
		img = mlx_xpm_file_to_image(data->mlx, "./skin/exit_open.xpm", &s, &s);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(data->mlx, "./skin/player.xpm", &s, &s);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, img, x * s, y * s);
	mlx_destroy_image(data->mlx, img);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

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

int	end_game(t_data *data)
{
	ft_printf("GG vous avez gagné !\n");
	if (data->map)
		free_tab_char(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}
