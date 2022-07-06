/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 14:02:00 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include <fcntl.h>

static int	ft_get_file_open_mode(t_token *token)
{
	int	mode;

	mode = 0;
	if (token->type == REDIR_RIGHT)
		mode = O_CREAT | O_TRUNC | O_WRONLY;
	if (token->type == SHIFT_RIGHT)
		mode = O_CREAT | O_APPEND | O_WRONLY;
	return (mode);
}

static char	*ft_get_file_name(t_tree *redirection_node)
{
	char	*file_name;

	t_token	*filename_token;
	if (! redirection_node || ! redirection_node->right)
		return (NULL);
	filename_token = redirection_node->right->content;
	file_name = ft_str(filename_token->value, filename_token->length);
	return (file_name);
}

static void ft_evaluate_redirection(t_tree *tree, t_evaluator_data *evaluator_data)
{
	char	*file_name;
	t_token	*token;
	int		mode;
	int		fd;

	if (! tree || ! evaluator_data)
		return ;
	token = tree->content;
	if (token->type != REDIR_RIGHT && token->type != SHIFT_RIGHT)
		return ;
	file_name = ft_get_file_name(tree);
	mode = ft_get_file_open_mode(token);
	if (! mode)
		return ((void)ft_free(file_name));
	fd = open(file_name, mode, 0644);
	if (evaluator_data->redirect_right < 0)
		evaluator_data->redirect_right = fd;
	else if (fd > 0)
		close(fd);
	ft_free(file_name);
}

static void	ft_evaluator_rec(t_tree	*tree, t_evaluator_data *evaluator_data, char **argenv)
{
	t_token	*token;

	if (! tree)
		return ;
	ft_expand_expression(tree->content, argenv);
	token = tree->content;
	if (ft_is_redirection(token->type))
		ft_evaluate_redirection(tree, evaluator_data);
	else if (token->type == SING_QUOT || token->type == DOUB_QUOT || token->type == EXPRESSION)
		evaluator_data->command = ft_arr_shift(evaluator_data->command, token->value);
	ft_evaluator_rec(tree->left, evaluator_data, argenv);
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
}
