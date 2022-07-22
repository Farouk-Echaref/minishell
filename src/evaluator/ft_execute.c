/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:01 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 00:31:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <errno.h>

static char *ft_join_command_path(char *path, char *command_name)
{
    char    *command_path;
    char    *temp;

    temp = ft_strjoin(path, "/");
    command_path = ft_strjoin(temp, command_name);
    temp = ft_free(temp);
    return (command_path);
}

static	char *ft_get_command_path(char	*command_name, char	**env)
{
	char	*path_env;
	char	**paths;
    char    *command_path;
    int     i;

	path_env = ft_evaluate_var("PATH", env);
	paths = ft_split(path_env, ':');
    i = 0;
	while (paths && paths[i])
	{
        command_path = ft_join_command_path(paths[i], command_name);
        if (access(command_path, X_OK) == 0)
            return (ft_arr_free(paths), command_path);
        command_path = ft_free(command_path);
		i++;
	}
	return (ft_arr_free(paths), NULL);
}

void	ft_execute(t_evaluator_data *evaluator_data, char **argenv)
{
	char	*path;
	char	**command;

	if (! evaluator_data)
		return ;
	command = evaluator_data->command;
	if (! command || ! *command)
		return ;
	if (evaluator_data->redirect_right >= 0)
	{
		dup2(evaluator_data->redirect_right, STDOUT_FILENO);
		close(evaluator_data->redirect_right);
	}
	if (evaluator_data->redirect_left >= 0)
	{
		dup2(evaluator_data->redirect_left, STDIN_FILENO);
		close(evaluator_data->redirect_left);
	}
	if (command[0][0] == '/' || command[0][0] == '.')
		path = ft_strdup(command[0]);
	else
		path = ft_get_command_path(command[0], argenv);
	if (! path || access(path, X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	execve(path, command, argenv);
}
