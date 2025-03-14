/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:06 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/14 20:39:08 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 832
# define HEIGHT 640

# define KEY_ESC 65307  // Echap
# define KEY_W 119      // Z
# define KEY_A 97       // Q
# define KEY_S 115      // S
# define KEY_D 100      // D
# define ARROW_UP 65362   // Flèche haut
# define ARROW_LEFT 65361 // Flèche gauche
# define ARROW_DOWN 65364 // Flèche bas
# define ARROW_RIGHT 65363 // Flèche droite

# define ERROR_INIT_MLX "Error : Can't intitialize the Minilibx\n"
# define ERROR_WINDOW "Error : Can't create the window\n"
# define ERROR_OPEN "Error : Can't open the file\n"

# define ERROR_BER "Error : The file type must be: .ber\n"
# define ERROR_LINE_EMPTY "Error : An empty line is in the map.\n"
# define ERROR_DUP "Error : Wrong quantities of P / E / C.\n"
# define ERROR_RECTANGLE "Error : The map is not rectangular.\n"
# define ERROR_ENCLOSED "Error : Map is not properly enclosed by walls.\n"
# define ERROR_DIMENSION "Error : Invalid map size.\n"
# define ERROR_NO_PLAYER "Error : No player position found in the map.\n"
# define ERROR_LETTER "Error : Wrong letter in the map :"
# define ERROR_FINISH "Error : The game can't be finished.\n"
# define ERROR_ALLOC "Error : Memory allocation failed\n"

# include "../sources/ultimate_libft/header/ultimate_libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

typedef struct s_data
{
	char	**map;
	int		width;
	int		height;
	int		player_y;
	int		player_x;
	int		exit_y;
	int		exit_x;
	int		collectibles;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;

//	utils.c
void	free_tab_char(char **tab);
void	exit_error(char *str);
void	exit_error_free(char *str, char *str_free, char **map);
void	free_map(char **map);

//	map_checker.c
int		check_extension(char *file);
int		check_quantities(char *str);
int		check_rectangular(char **map);
int		check_empty_line(char *line, int allow_spaces);
int		check_lines(char **map);
void	free_and_exit(char *line, char *map, int fd);

//	map_getter.c
char	*read_map(int fd_map);
char	**get_map_str(char *filename, t_data *data);
int		parse_map(t_data *data, char *file);

//	map_printer.c
int		init_mlx(t_data *data);
int		create_window(t_data *data);
void	put_texture(t_data *data, int x, int y, char c);
void	draw_map(t_data *data);
int		is_map_enclosed(t_data *data);
void	flood_fill(char **tab, t_data *data, int x, int y);
int		is_map_valid(t_data *data);
void	print_key(int keycode);
int		is_map_valid(t_data *data);
void	count_collectibles(t_data *data, char **map);
void	reset_door_if_needed(t_data *data);
int		find_player(t_data *data);
int		find_exit(t_data *data);
int		validate_map(char *str, char ***map);
void	get_map_dimensions(t_data *data, char **map);
int		end_game(t_data *data);

//	so_long.c
int		main(int argc, char **argv);

#endif