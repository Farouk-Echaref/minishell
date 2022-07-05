/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:56:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

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
