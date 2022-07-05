/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 15:18:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

static void	ft_evaluator_rec(t_tree	*tree, char	***command, char **argenv)
{
	t_token	*token;

	if (! tree)
		return ;
	ft_expand_expression(tree->content, argenv);
	token = tree->content;
	*command = ft_arr_shift(*command, token->value);
	ft_evaluator_rec(tree->left, command, argenv);
}

void	ft_evaluator(t_tree	*tree, char **argenv)
{
	char	**command;

	command = NULL;
	command = (char **)malloc(sizeof(char *));
	*command = NULL;
	ft_evaluator_rec(tree, &command, argenv);
	ft_execute(command, argenv);
	command = ft_free(command);
}
