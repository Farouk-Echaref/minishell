/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 07:01:04 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

char	*ft_check_echo(char **command)
{
	if (command[1][2] == 'n')
	{
		free(command[1]);
		return (ft_strdup("-n"));
	}
	return (command[1]);
}

void	ft_execute(char **command, char **argenv)
{
	int		pid;
	char	*path;

	if (! command || ! *command)
		return ;
	if (ft_strncmp(command[0], "echo", 4) == 0)
		command[1] = ft_check_echo(command);
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

static void	ft_evaluator_rec(t_tree	*tree, char	***command, char **argenv)
{
	t_token	*token;
	char	*str;

	if (! tree)
		return ;
	ft_expand_expression(tree->content, argenv);
	token = tree->content;
	str = ft_str(token->value, token->length);
	*command = ft_arr_shift(*command, str);
	ft_evaluator_rec(tree->left, command, argenv);
}

void	ft_evaluator(t_tree	*tree, char **argenv)
{
	char	**command;
	int		i;

	command = NULL;
	command = (char **)malloc(sizeof(char *));
	*command = NULL;
	ft_evaluator_rec(tree, &command, argenv);
	if (argenv) {}
	ft_execute(command, argenv);
	i = 0;
	while (command[i] != NULL)
	{
		command[i] = ft_free(command[i]);
		i++;
	}
	command = ft_free(command);
}
