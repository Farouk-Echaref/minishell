/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 02:32:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include "redirections/redirections.h"

static char	**ft_push_star_values(
	t_evaluator_data *evaluator_data, t_token *token)
{
	char		**star_token_values;
	char		**temp;

	star_token_values = ft_split(token->value, ' ');
	temp = star_token_values;
	while (star_token_values && *star_token_values)
	{
		evaluator_data->command
			= ft_arr_push(evaluator_data->command, *star_token_values);
		star_token_values++;
	}
	temp = ft_free(temp);
	return (evaluator_data->command);
}

static void	ft_evaluate(t_tree *tree,
	t_evaluator_data *evaluator_data, t_token *token)
{
	evaluator_data->expand_star = 1;
	if (evaluator_data->command
		&& ft_strcmp(evaluator_data->command[0], "export") == 0)
		evaluator_data->expand_star = 0;
	if (ft_is_redirection(ft_get_token_tree(tree)->type))
		ft_expand_expression(tree->right->content, evaluator_data, 1, 1);
	ft_expand_expression(tree->content, evaluator_data, 1, 0);
	if (! evaluator_data->ok)
		return ;
	if (ft_is_redirection(token->type))
		ft_evaluate_redirection(tree, evaluator_data);
	else if (token->type == STAR)
		evaluator_data->command = ft_push_star_values(evaluator_data, token);
	else if (
		token->type == SING_QUOT
		|| token->type == DOUB_QUOT
		|| token->type == EXPRESSION
	)
		evaluator_data->command
			= ft_arr_push(evaluator_data->command, ft_strdup(token->value));
}

static void	ft_evaluator_rec(t_tree	*tree, t_evaluator_data *evaluator_data)
{
	t_token		*token;

	if (! tree)
		return ;
	token = tree->content;
	if (token->type == SUB_CMD)
		return (ft_run_command(token->value));
	if (token->type == AND_OPR)
		return (ft_and_opr(tree));
	if (token->type == OR_OPR)
		return (ft_or_opr(tree));
	if (token->type == PIPE)
		return (ft_pipe(tree));
	ft_evaluator_rec(tree->left, evaluator_data);
	ft_evaluate(tree, evaluator_data, token);
}

void	ft_evaluator(t_tree	*tree)
{
	t_evaluator_data	evaluator_data;
	char				*command_name;

	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data);
	command_name = evaluator_data.command[0];
	if (command_name && evaluator_data.ok)
	{
		if (ft_should_run_on_main_process(command_name))
			ft_execute(&evaluator_data);
		else
			ft_execute_fork(&evaluator_data);
	}
	ft_arr_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
}

void	ft_evaluator_no_fork(t_tree	*tree)
{
	t_evaluator_data	evaluator_data;
	char				*command_name;

	ft_set_signals_default();
	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data);
	command_name = evaluator_data.command[0];
	if (command_name && evaluator_data.ok)
		ft_execute(&evaluator_data);
	else
		exit(EXIT_SUCCESS);
}
