/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:06 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 14:55:06 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define ERROR_BER "Error : The file type must be: .ber\n"
# define ERROR_EMPTY_LINE "Error : Map has an empty line in it\n"
# define ERROR_DUP "Error : Wrong quantities of P / E / C.\n"
# define ERROR_RECTANGLE "Error : The map is not rectangular.\n"
# define ERROR_ENCLOSED "Error : Map is not properly enclosed by walls.\n"
# define ERROR_DIMENSION "Error : Invalid map size.\n"
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

//	map_parsing_1.c
int		check_extension(char *file);
int		check_lines(char **map);
int		check_quantities(char *str);
int		check_rectangular(char **map);
int		is_map_enclosed(t_data *data);

//	map_parsing_2.c
void	get_map_dimensions(t_data *data, char **map);
void	count_collectibles(t_data *data, char **map);
int		validate_map(char *str, char ***map);
int		parse_map(t_data *data, char *file);

//	map_parsing_3.c
char	**duplicate_map(char **map, int height);
void	flood_fill(char **tab, t_data *data, int x, int y);
int		is_map_solvable(char **map, int width, int height);
int		is_map_valid(t_data *data);

//	map_getter.c
char	*append_line(char *map, char *line);
char	*read_map(int fd_map);
char	**get_map_str(char *filename, t_data *data);
int		find_player(t_data *data);
int		find_exit(t_data *data);

//	map_printer.c
int		init_mlx(t_data *data);
int		create_window(t_data *data);
void	put_texture(t_data *data, int x, int y, char c);
void	draw_map(t_data *data);
int		end_game(t_data *data);

//	so_long.c
void	init_data(t_data *data);
void	move_player(t_data *data, int dx, int dy);
int		handle_key(int keycode, void *param);
int		main(int argc, char **argv);

//	utils.c
int		check_empty_line(char *line, int allow_spaces);
void	free_tab_char(char **tab);
void	exit_error(char *str);
void	exit_error_free(char *str, char *str_free, char **map);
void	free_and_exit(char *line, char *map, int fd);

#endif