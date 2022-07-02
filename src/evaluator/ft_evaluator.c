/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 06:49:45 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "utils/utils.h"
#include "libft/libft.h"
#include <unistd.h>

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

static int	ft_arr_size(char **arr)
{
	int	count;

	count = 0;
	while (arr[count++]);
	return (count - 1);
}

void	ft_reverse_arr(char **arr)
{
	int		i;
	int		j;
	char	*str;

	if (! arr)
		return ;
	j = ft_arr_size(arr) - 1;
	i = 0;
	while (i < j)
	{
		str = arr[i];
		arr[i] = arr[j];
		arr[j] = str;
		i++;
		j--;
	}
}

char	**ft_arr_shift(char **command, char *str)
{
	char	**new_arr;
	int		new_size;
	int		i;

	new_size = ft_arr_size(command) + 2;
	new_arr = (char **)malloc(sizeof(char *) * new_size);
	i = 0;
	new_arr[0] = str;
	while (command[i])
	{
		new_arr[i + 1] = command[i];
		i++;
	}
	command = ft_free(command);
	new_arr[i + 2] = NULL;
	return (new_arr);
}

void	ft_execute(char **command, char **argenv)
{
	int pid;

	if (! command || ! *command)
		return ;
	if ((pid = fork()) == -1)
		return ;
	if (pid == 0)
	{
		char *path = ft_strjoin("/bin/", command[0]);
		execve(path, command, argenv);
	} else
		waitpid(-1, NULL, 0);
}

void	ft_evaluator_rec(t_tree	*tree, char	***command)
{
	t_token	*token;

	if (! tree)
		return ;
	token = tree->content;
	*command = ft_arr_shift(*command, ft_str(token->value, token->length));
	ft_evaluator_rec(tree->left, command);
}

void	ft_evaluator(t_tree	*tree, char **argenv)
{
	char	**command;
	int		i;

	command = NULL;
	command = (char **)malloc(sizeof(char *));
	*command = NULL;
	ft_evaluator_rec(tree, &command);
	ft_execute(command, argenv);
	i = 0;
	while (command[i] != NULL)
	{
		command[i] = ft_free(command[i]);
		i++;
	}
	command = ft_free(command);
}
