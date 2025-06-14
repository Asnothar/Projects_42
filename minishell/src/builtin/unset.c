/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broboeuf <broboeuf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:06:08 by garside           #+#    #+#             */
/*   Updated: 2025/06/05 00:20:47 by broboeuf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_from_list(t_env **list, char *name)
{
	t_env	*current;
	t_env	*prev;

	current = *list;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*list = current->next;
			if (current->next)
				current->next->prev = prev;
			free(current->name);
			free(current->content);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_data *data)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = data->cmd_list;
	if (!cmd->args[1])
		return (0);
	while (cmd->args[i])
	{
		remove_from_list(&data->env, cmd->args[i]);
		remove_from_list(&data->export, cmd->args[i]);
		i++;
	}
	return (0);
}

void	exit_cmd_not_found(t_data *data, t_cmd *cmd, char *arg)
{
	print_cmd_error(arg);
	if (cmd)
		free_cmd_list(data);
	if (data)
		free_data(data);
	exit(127);
}

void	print_cmd_error(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	if (ft_strchr(cmd, '/'))
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}
