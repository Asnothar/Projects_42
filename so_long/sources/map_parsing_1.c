/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/14 19:48:22 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_extension(char *file)
{
	size_t	len;

	len = strlen(file);
	if (len < 4 || strcmp(file + len - 4, ".ber") != 0)
	{
		ft_printf(ERROR_BER);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_empty_line(map[i], 1))
			return (ft_printf(ERROR_LINE_EMPTY), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_quantities(char *str)
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
			return (ft_printf("%s %c\n", ERROR_LETTER, str[i]), EXIT_FAILURE);
		if (str[i] == 'E')
			c_e++;
		if (str[i] == 'C')
			c_c++;
		if (str[i] == 'P')
			c_p++;
		i++;
	}
	if (c_c < 1 || c_e != 1 || c_p != 1)
		return (ft_printf(ERROR_DUP), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rectangular(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf(ERROR_RECTANGLE);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	is_map_enclosed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
