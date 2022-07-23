/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 22:09:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include "redirections/redirections.h"

static void	ft_evaluator_rec(t_tree	*tree, t_evaluator_data *evaluator_data)
{
	t_token	*token;

	if (! tree)
		return ;
	token = tree->content;
	if (token->type == AND_OPR)
		return (ft_and_opr(tree));
	if (token->type == OR_OPR)
		return (ft_or_opr(tree));
	if (token->type == PIPE)
		return (ft_pipe(tree));
	ft_evaluator_rec(tree->left, evaluator_data);
	ft_expand_expression(tree->content);
	if (ft_is_redirection(token->type))
		ft_evaluate_redirection(tree, evaluator_data);
	else if (token->type == SING_QUOT || token->type == DOUB_QUOT || token->type == EXPRESSION)
		evaluator_data->command = ft_arr_push(evaluator_data->command, token->value);
}

void	ft_evaluator(t_tree	*tree)
{
	t_evaluator_data	evaluator_data;

	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data);
	ft_execute(&evaluator_data);
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
	exit(EXIT_SUCCESS);
}

void	ft_evaluator_fork(t_tree	*tree)
{
	int					pid;
	int					status;

	pid = ft_fork();
	if (pid != 0)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 200)
			exit(g_.exit_status);
		g_.exit_status = WEXITSTATUS(status);
	} else
		ft_evaluator(tree);
}
