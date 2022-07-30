/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:01 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/28 15:23:02 by mzarhou          ###   ########.fr       */
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

static	char *ft_get_command_path(char	*command_name)
{
	char	*path_env;
	char	**paths;
    char    *command_path;
    int     i;

	path_env = ft_evaluate_var("PATH");
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

void	ft_execute(t_evaluator_data *evaluator_data)
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
	if (ft_is_builtin(command[0]))
		return (ft_select_builtin_command(command[0])(command));
	if (ft_strchr(command[0], '/') != NULL)
		path = ft_strdup(command[0]);
	else
	{
		path = ft_get_command_path(command[0]);
		if (! path || ft_strlen(command[0]) == 0 || access(path, X_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
	}
	execve(path, command, ft_lst2arr(g_.env));
	perror("minishell");
	exit(127);
}


void	ft_execute_fork(t_evaluator_data *evaluator_data)
{
	int	pid;
	int	status;

	pid = ft_fork();
	if (pid == 0)
	{
		ft_set_signals_default();
		ft_execute(evaluator_data);
	}
	else
	{
		// main process
		waitpid(pid, &status, 0);
		g_.exit_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
		{
			g_.exit_status = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGQUIT)
				printf("Quit: 3\n");
			if (WTERMSIG(status) == SIGINT)
				printf("\n");
		}
	}
}
