/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_opr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:33:22 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 14:16:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_and_opr(t_tree *node, char **env)
{
	int	pid;
	int	status;

	pid = ft_fork();
	if (pid == 0)
		ft_evaluator(node->left, env);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
	ft_evaluator(node->right, env);
}
