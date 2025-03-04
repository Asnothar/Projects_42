/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:19:50 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/26 12:06:00 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	search_path(char **env)
{
	char	*str;
	int		i;

	str = "PATH=";
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(str, env[i], 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	exec_path(char *argv, char **env)
{
	char	**path;
	char	**cmd;
	char	*path_cmd;
	int		i;

	path = ft_split(env[search_path(env)], ':');
	cmd = ft_split(argv, ' ');
	i = -1;
	while (path[++i] != NULL)
	{
		path_cmd = ft_strjoin(path[i], ft_strjoin("/", cmd[0]));
		if (access(argv, F_OK | X_OK) == 0)
		{
			execve(argv, cmd, env);
			return (free_tab(path), free_all(cmd, &path_cmd), exit(1));
		}
		else if (access(path_cmd, F_OK | X_OK) == 0)
		{
			execve(path_cmd, cmd, env);
			return (free_tab(path), free_all(cmd, &path_cmd), exit(1));
		}
		free(path_cmd);
	}
	return (free_all(path, cmd), exit(1));
}

void	child_1(char *file, char *cmd, int pipefd[2], char **env)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (perror("Erreur Child 1"), exit(1));
	}
	close(pipefd[0]);
	if (dup2(fd, STDIN_FILENO) == -1
		|| dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		close(fd);
		close(pipefd[0]);
		return (perror("Erreur Child 1"), exit(1));
	}
	close(fd);
	close(pipefd[1]);
	if (cmd[0] == '\0')
		exit(1);
	exec_path(cmd, env);
}

void	child_2(char *file, char *cmd, int pipefd[2], char **env)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (perror("Erreur fd Child 2"), exit(1));
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1
		|| dup2(fd, STDOUT_FILENO) == -1)
		return (perror("Erreur  Child 2"), exit(1));
	close(fd);
	close(pipefd[0]);
	if (cmd[0] == '\0')
		exit(1);
	exec_path(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (perror("Erreur argc :"), 1);
	if (pipe(pipefd) == -1)
		return (perror("Erreur pipe :"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Erreur fork 1:"), 1);
	else if (pid1 == 0)
		child_1(argv[1], argv[2], pipefd, env);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Erreur fork 2:"), 1);
	else if (pid2 == 0)
		child_2(argv[4], argv[3], pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

// int proc()
// {

// 	fd_in = open(argv[1], O_RDONLY);
// 	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd_in < 0 || fd_out < 0)
// 		return (perror("Error"), 1);
// 	if (pipe(pipefd) == -1)
// 		return (perror("pipe"), 1);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		dup2(fd_in, 0);
// 		dup2(pipefd[1], 1);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		close(fd_in);
// 		close(fd_out);
// 		execlp("ls", "ls", "-l", NULL);
// 		perror("exec cmd1");
// 		exit(1);
// 	}
// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		dup2(pipefd[0], 0);
// 		dup2(fd_out, 1);
// 		close(pipefd[1]);
// 		close(pipefd[0]);
// 		close(fd_in);
// 		close(fd_out);
// 		execlp("wc", "wc", "-l", NULL);
// 		perror("exec cmd2");
// 		exit(1);
// 	}
// }
