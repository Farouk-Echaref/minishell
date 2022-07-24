/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 15:37:48 by mzarhou          ###   ########.fr       */
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
	)
		return (1);
	return (0);
}

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
	char				*command_name;

	ft_init_evaluator_data(&evaluator_data);
	ft_evaluator_rec(tree, &evaluator_data);
	command_name = evaluator_data.command[0];
	if (ft_should_run_on_main_process(command_name))
	{
		printf("main process\n");
		ft_execute(&evaluator_data);
	}
	else
	{
		printf("child process\n");
		ft_execute_fork(&evaluator_data);
	}
	evaluator_data.command = ft_free(evaluator_data.command);
	if (evaluator_data.redirect_right >= 0)
		close(evaluator_data.redirect_right);
	if (evaluator_data.redirect_left >= 0)
		close(evaluator_data.redirect_left);
}
