/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:35:34 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 16:22:12 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->width = 0;
	data->height = 0;
	data->player_y = 0;
	data->player_x = 0;
	data->exit_y = 0;
	data->exit_x = 0;
	data->collectibles = 0;
	data->moves = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
}

void	move_player(t_data *data, int dx, int dy)
{
	int	n_x;
	int	n_y;

	n_x = data->player_x + dx;
	n_y = data->player_y + dy;
	if ((n_x < 0 || n_x >= data->width || n_y < 0 || n_y >= data->height)
		|| (data->map[n_y][n_x] == '1'))
		return ;
	else if (data->map[n_y][n_x] == 'C')
	{
		data->collectibles--;
		data->map[n_y][n_x] = '0';
	}
	else if (data->map[n_y][n_x] == 'E' && data->collectibles == 0)
		end_game(data);
	else if (data->player_y == data->exit_y && data->player_x == data->exit_x)
		data->map[data->player_y][data->player_x] = 'E';
	else
		data->map[data->player_y][data->player_x] = '0';
	data->player_x = n_x;
	data->player_y = n_y;
	data->map[n_y][n_x] = 'P';
	data->moves++;
	ft_printf("\033[A\33[2KNombre de pas : %d\n", data->moves);
	draw_map(data);
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == ARROW_UP)
		move_player(data, 0, -1);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_player(data, 0, 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_player(data, -1, 0);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_player(data, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_data(&data);
		if (parse_map(&data, argv[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (!is_map_valid(&data))
			return (EXIT_FAILURE);
		if (init_mlx(&data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (create_window(&data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		draw_map(&data);
		mlx_key_hook(data.win, handle_key, &data);
		mlx_hook(data.win, 17, 0, end_game, &data);
		mlx_loop(data.mlx);
	}
	return (EXIT_SUCCESS);
}
