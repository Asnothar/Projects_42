/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:35:34 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/10 17:05:23 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void init_data(t_data *data)
{
    // Initialisation des membres de la structure à des valeurs par défaut
    data->map = NULL; // Aucun plan de carte par défaut
    data->width = 0; // Largeur de la carte
    data->height = 0; // Hauteur de la carte
    data->player_y = 0; // Position Y du joueur
    data->player_x = 0; // Position X du joueur
    data->collectibles = 0; // Nombre de collectibles
    data->moves = 0; // Nombre de mouvements du joueur
    data->mlx = NULL; // Pointeur vers l'instance MLX
    data->win = NULL; // Pointeur vers la fenêtre
    data->img = NULL; // Pointeur vers une image (si nécessaire)
}

int	end_game(t_data *data)
{
	ft_printf("Félicitations, vous avez gagné en %d mouvements !\n", data->moves);

	if (data->map)
		free_map(data->map);
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

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x = data->player_x + dx;
	int	new_y = data->player_y + dy;


	ft_printf("width : %d | height : %d\n",  new_x, new_y);
	if (new_x < 0 || new_x >= data->width || new_y < 0 || new_y >= data->height)
		return;
	if (data->map[new_y][new_x] == '1')
		return;
	if (data->map[new_y][new_x] == 'C')
	{
		data->collectibles--;
		data->map[new_y][new_x] = '0';
	}
	if (data->map[new_y][new_x] == 'E' && data->collectibles == 0)
	{
		end_game(data);
		return;
	}
	data->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_y][new_x] = 'P';
	data->moves++;
	draw_map(data);
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_printf("Keycode : %d\n", keycode);
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

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		if (extension_checker(argv[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_data(&data);
		if (parse_map(&data, argv[1]) == EXIT_FAILURE)
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
