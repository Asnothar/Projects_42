/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:06 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/04 19:05:04 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 800
# define HEIGHT 600
# define ERROR_BER "Erreur : Le fichier doit être au format .ber\n"
# define ERROR_INIT_MLX "Erreur d'initialisation de MiniLibX\n"
# define ERROR_WINDOW "Erreur de création de fenêtre\n"
# define ERROR_OPEN "Erreur lors de l'ouverture de la map\n"

# include "../sources/ultimate_libft/header/ultimate_libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

typedef struct s_data
{
	char **map;
	int	width;
	int height;
	int	player_y;
	int	player_x;
	int	collectibles;
	int	moves;
	void	*mlx; // Pointeur vers l'instance MLX
	void	*win; // Pointeur vers la fenêtre
	void	*img; // Pointeur vers l'image (si nécessaire)
}	t_data;

int	main(int argc, char** argv);

int		init_mlx(t_data *data);
int		create_window(t_data *data);
void	draw_map(t_data *data);
void	handle_events(t_data *data);
t_data	*parse_map(const char *filename);
int		parse_map_wrapper(const char *filename, t_data **data);


#endif
