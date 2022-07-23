/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:14:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 14:15:30 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_pipe_left_fork(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		ft_evaluator(tree, env);
	}
}

void	ft_pipe_right_fork(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		ft_evaluator(tree, env);
	}
}

void	ft_pipe(t_tree *node, char **env)
{
	int	fds[2];

	int	status;

	if (pipe(fds) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	ft_pipe_left_fork(node->left, env, fds);
	ft_pipe_right_fork(node->right, env, fds);
	close(fds[0]);
	close(fds[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}
