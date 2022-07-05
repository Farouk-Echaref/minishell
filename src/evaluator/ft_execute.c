/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:01 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:32:31 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_execute(char **command, char **argenv)
{
	int		pid;
	char	*path;

	if (! command || ! *command)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		path = ft_strjoin("/bin/", command[0]);
		execve(path, command, argenv);
	}
	else
		waitpid(-1, NULL, 0);
}
