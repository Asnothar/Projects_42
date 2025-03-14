/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:22:46 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/14 17:15:07 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_empty_line(char *line, int allow_spaces)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && (!allow_spaces
				|| (line[i] != ' ' && line[i] != '\t')))
			return (0);
		i++;
	}
	return (1);
}

void	free_tab_char(char **tab)
{
	int	y;

	y = 0;
	if (!tab)
		return ;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

void	exit_error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	exit_error_free(char *str, char *str_free, char **map)
{
	free(str_free);
	free_tab_char(map);
	perror(str);
	exit(1);
}

void	free_and_exit(char *line, char *map, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (line)
		free(line);
	get_next_line(-1);
	free(map);
	close(fd);
	exit_error("Map has an empty line in it\n");
}
