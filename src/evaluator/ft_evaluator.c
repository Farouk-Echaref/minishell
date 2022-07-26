/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 22:54:06 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include "redirections/redirections.h"

static int	ft_should_run_on_main_process(char *command_name)
{
	if (
		ft_strcmp(command_name, "exit") == 0
		|| ft_str_start_with(command_name, "exit ")
		|| ft_strcmp(command_name, "unset") == 0
		|| ft_str_start_with(command_name, "unset ")
		|| ft_strcmp(command_name, "export") == 0
		|| ft_str_start_with(command_name, "export ")
		|| ft_strcmp(command_name, "cd") == 0
		|| ft_str_start_with(command_name, "cd ")
		|| ft_strcmp(command_name, "pwd") == 0
		|| ft_str_start_with(command_name, "pwd ")
	)
		return (1);
	return (0);
}

void	ft_expand_tokens(t_tree *node)
{
	if (! node)
		return ;
	if (ft_is_redirection(ft_get_token_tree(node)->type))
		ft_expand_expression(node->content, node->right->content);
	else
		ft_expand_expression(node->content, NULL);
}

static char	**ft_push_star_values(t_evaluator_data *evaluator_data, t_token *token)
{
	char		**star_token_values;
	char		**temp;

	star_token_values = ft_split(token->value, ' ');
	temp = star_token_values;
	while (star_token_values && *star_token_values)
	{
		evaluator_data->command = ft_arr_push(evaluator_data->command, *star_token_values);
		star_token_values++;
	}
	temp = ft_free(temp);
	star_token_values = NULL;
	return (evaluator_data->command);
}

static void	ft_evaluator_rec(t_tree	*tree, t_evaluator_data *evaluator_data)
{
	t_token		*token;

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
	if (! evaluator_data->ok)
		return ;
	ft_expand_tokens(tree);
	if (ft_is_redirection(token->type))
		ft_evaluate_redirection(tree, evaluator_data);
	else if (token->type == STAR) {
		evaluator_data->command = ft_push_star_values(evaluator_data, token);
	} else if (
		token->type == SING_QUOT
		|| token->type == DOUB_QUOT
		|| token->type == EXPRESSION
	)
		evaluator_data->command = ft_arr_push(evaluator_data->command, token->value);
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
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
}

void	ft_evaluator_no_fork(t_tree	*tree)
{
	t_evaluator_data	evaluator_data;
	char				*command_name;

	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data);
	command_name = evaluator_data.command[0];
	if (command_name)
		ft_execute(&evaluator_data);
	else
		exit(EXIT_SUCCESS);
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
}
