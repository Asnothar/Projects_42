/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/07 19:26:36 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	extension_checker(char *file)
{
	size_t	len;

	len = strlen(file);
	if (len < 4 || strcmp(file + len - 4, ".ber") != 0)
		return (ft_printf("%s", ERROR_BER), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	if_empty_line(char **map)
{
	int	i;
	int	j;
	int	empty_line_found;

	i = 0;
	empty_line_found = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n')
				break; // La ligne contient au moins un caractère valide
			j++;
		}
		if (map[i][j] == '\0') // Si on a parcouru toute la ligne et trouvé que des espaces/tabs
			empty_line_found = 1;
		i++;
	}
	if (empty_line_found)
		return (ft_printf("Error: empty line in map\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	duplicate_handling_map(char *str)
{
	int	i;
	int	c_c;
	int	c_e;
	int	c_p;

	i = 0;
	c_c = 0;
	c_e = 0;
	c_p = 0;
	while (str[i])
	{
		if (!strchr("10PCE\n", str[i]))
			return (ft_printf("%s", ERROR_DUP), EXIT_FAILURE);
		if (str[i] == 'E')
			c_e++;
		if (str[i] == 'C')
			c_c++;
		if (str[i] == 'P')
			c_p++;
		i++;
	}
	if (c_c < 1 || c_e != 1 || c_p != 1)
		return (ft_printf("%s", ERROR_DUP), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_rectangular(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (ft_printf("%s", ERROR_RECTANGLE), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	if_map_not_valid(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
			return (ft_printf("Ligne vide dans la map\n"), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
