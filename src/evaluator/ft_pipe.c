/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:14:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 16:41:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

int	ft_pipe_left_fork(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		ft_evaluator(tree, env);
	}
	return (pid);
}

int	ft_pipe_right_fork(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		ft_evaluator(tree, env);
	}
	return (pid);
}

void	ft_pipe(t_tree *node, char **env)
{
	int	fds[2];
	int	status;
	int	left_pid;
	int	right_pid;

	if (pipe(fds) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	left_pid = ft_pipe_left_fork(node->left, env, fds);
	right_pid = ft_pipe_right_fork(node->right, env, fds);
	close(fds[0]);
	close(fds[1]);
	waitpid(left_pid, &status, 0);
	waitpid(right_pid, &status, 0);
	exit(WEXITSTATUS(status));
}
