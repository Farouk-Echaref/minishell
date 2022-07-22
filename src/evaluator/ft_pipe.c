/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:14:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/22 19:17:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

static	pid_t	ft_fork()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	return (pid);
}

void	ft_pipe_left(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		ft_evaluator(tree, env);
		exit(EXIT_SUCCESS);
	}
}

void	ft_pipe_right(t_tree *tree, char **env, int fds[2])
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		ft_evaluator(tree, env);
		exit(EXIT_SUCCESS);
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
	ft_pipe_left(node->left, env, fds);
	ft_pipe_right(node->right, env, fds);
	close(fds[0]);
	close(fds[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}
