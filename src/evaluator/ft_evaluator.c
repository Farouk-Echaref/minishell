/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 19:00:39 by mzarhou          ###   ########.fr       */
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
	if (token->type == AND_OPR)
		return (ft_and_opr(tree, argenv));
	if (token->type == OR_OPR)
		return (ft_or_opr(tree, argenv));
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

	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data, argenv);
	ft_execute(&evaluator_data, argenv);
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
	exit(EXIT_SUCCESS);
}

void	ft_evaluator_fork(t_tree	*tree, char **argenv)
{
	int					pid;
	int					status;

	pid = ft_fork();
	if (pid != 0)
	{
		waitpid(-1, &status, 0);
		g_.exit_status = WEXITSTATUS(status);
		if (g_.exit_status == 200)
			exit(1);
	} else
		ft_evaluator(tree, argenv);
}
