/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:01 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 14:02:26 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_execute(t_evaluator_data *evaluator_data, char **argenv)
{
	int		pid;
	char	*path;
	char	**command;

	if (! evaluator_data)
		return ;
	command = evaluator_data->command;
	if (! command || ! *command)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
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
		path = ft_strjoin("/bin/", command[0]);
		execve(path, command, argenv);
	}
	else
		waitpid(-1, NULL, 0);
}
