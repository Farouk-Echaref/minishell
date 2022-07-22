/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/22 18:56:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include "redirections/redirections.h"

static void	ft_evaluator_rec(t_tree	*tree, t_evaluator_data *evaluator_data, char **argenv)
{
	t_token	*token;

	if (! tree)
		return ;
	token = tree->content;
	if (token->type == PIPE)
		return (ft_pipe(tree, argenv));
	ft_evaluator_rec(tree->left, evaluator_data, argenv);
	ft_expand_expression(tree->content, argenv);
	if (ft_is_redirection(token->type))
		ft_evaluate_redirection(tree, evaluator_data, argenv);
	else if (token->type == SING_QUOT || token->type == DOUB_QUOT || token->type == EXPRESSION)
		evaluator_data->command = ft_arr_push(evaluator_data->command, token->value);
}

void	ft_evaluator(t_tree	*tree, char **argenv)
{
	t_evaluator_data	evaluator_data;
	int					pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid != 0)
	{
		waitpid(-1, NULL, 0);
		return ;
	}
	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data, argenv);
	ft_execute(&evaluator_data, argenv);
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
}
