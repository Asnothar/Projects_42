/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:35:34 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/04 19:19:00 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_printf("%s", ERROR_INIT_MLX), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	create_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "So Long");
	if (!data->win)
		return (ft_printf("%s", ERROR_WINDOW), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	put_texture(t_data *data, int x, int y, char c)
{
	int	s;

	if (!data || !data->mlx || !data->win)
		return;

	s = 64;
	if (c == '1')
		data->img = mlx_xpm_file_to_image(data->mlx, "wall.xpm", &s, &s);
	else if (c == '0')
		data->img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &s, &s);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx, "collectible.xpm", &s, &s);
	else if (data->collectibles == 0 && c == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &s, &s);
	else if (c == 'E' && data->collectibles != 0)
		data->img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &s, &s);
	else if (c == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx, "player.xpm", &s, &s);

	if (!data->img)
	{
		printf("Erreur lors du chargement de l'image pour le caractère '%c'\n", c);
		return;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 64, y * 64);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_map(t_data *data)
{
	if (!data || !data->map || !data->mlx || !data->win)
		return;

	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			put_texture(data, j, i, data->map[i][j]);
			j++;
		}
		i++;
	}
}

void	end_game(t_data *data)
{
	ft_printf("Félicitations, vous avez gagné !\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (data->map[new_y][new_x] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
		if (data->map[new_y][new_x] == 'E')
			end_game(data);
		if (data->map[new_y][new_x] == 'C')
		{
			data->collectibles--;
			data->map[new_y][new_x] = '0';
		}
		data->moves++;
		ft_printf("Mouvements : %d\n", data->moves);
		draw_map(data);
	}
}

int	handle_key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	else if (keycode == 13)
		move_player(data, 0, -1);
	else if (keycode == 1)
		move_player(data, 0, 1);
	else if (keycode == 0)
		move_player(data, -1, 0);
	else if (keycode == 2)
		move_player(data, 1, 0);
	return (0);
}

int	handle_key_release(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

void	handle_events(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, handle_key_release, data);
}

int	main(int argc, char	**argv)
{
	t_data	*data;

	if (argc == 2)
	{
		if (parse_map_wrapper(argv[1], &data) == EXIT_FAILURE)
			return (printf("Fail Parsing\n"), EXIT_FAILURE);
		if (!data)
			return (printf("Data is NULL after parsing\n"), EXIT_FAILURE);
		if (init_mlx(data) == EXIT_FAILURE)
			return (printf("Fail Init\n"), EXIT_FAILURE);
		if (create_window(data) == EXIT_FAILURE)
			return (printf("Fail Window\n"), EXIT_FAILURE);
		printf("test 0\n");
		printf("Première ligne, longueur : %lu\n", strlen(data->map[0]));
		printf("BLABLA\n");
		if (!data || !data->map || !data->mlx || !data->win)
			return (printf("MLX or Window is NULL\n"), EXIT_FAILURE);
		draw_map(data);
		printf("BLABLA 2\n");
		mlx_loop(data->mlx);
	}
	return (EXIT_SUCCESS);
}

