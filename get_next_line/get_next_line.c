/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:46:19 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/03 13:54:20 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *str)
{
	char	*stash;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (NULL);
	stash = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	str[i + 1] = '\0';
	return (stash);
}

char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = fill_line_buffer(fd, stash, buffer);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = set_line(line);
	return (line);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <file_name>\n", argv[0]);
// 		return (1);
// 	}
// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	int	count = 0; 
// 	if (count < 5)
// 	{
// 		printf("%s", get_next_line(fd));
// 		count++;
// 	}
// 	if (close(fd) < 0)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }
