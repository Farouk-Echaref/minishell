/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:25:09 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 02:06:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_checker/syntax_checker.h"

int	ft_check_matching(t_token *t)
{
	if (t->length == 1 && (
			t->type == SING_QUOT
			|| t->type == DOUB_QUOT
		)
	)
		return (0);
	if (t->type == SUB_CMD && t->length <= 2)
		return (0);
	return (1);
}

int	ft_check_subcommand(t_list *node)
{
	t_lexer	*lxr;
	t_data	data;
	char	*command_str;
	int		result;
	t_token	*t;

	data.tokens = NULL;
	data.tree = NULL;
	if (! node || ft_has(LEFT, node->prev) == 1)
		return (0);
	t = ft_get_token(node);
	command_str = ft_str(t->value + 1, t->length - 2);
	lxr = ft_init_lexer(command_str);
	data.tokens = ft_lexer(lxr);
	result = ft_check_syntax(data.tokens);
	ft_destroy_lexer(lxr);
	ft_lstclear(&data.tokens, &ft_free_token_no_value);
	command_str = ft_free(command_str);
	return (result);
}

int	ft_check_redirection(t_list *node)
{
	t_token	*t;
	t_list	*next_node;

	if (! node || ! node->next)
		return (0);
	next_node = node->next;
	if (ft_get_token_type(next_node) == WHITE_SPACE)
		next_node = next_node->next;
	if (! next_node)
		return (0);
	t = ft_get_token(next_node);
	if (
		t->type == AND_OPR
		|| t->type == OR_OPR
		|| t->type == PIPE
		|| ft_is_redirection(t->type)
	)
		return (0);
	return (1);
}

int	ft_check_expression(t_token *t)
{
	char	*str;

	str = ft_str(t->value, t->length);
	if (ft_strchr(str, '\\'))
		return (ft_free(str), 0);
	str = ft_free(str);
	return (1);
}

int	ft_check_syntax(t_list *tokens)
{
	t_token	*t;

	while (tokens)
	{
		t = ft_get_token(tokens);
		if (ft_check_matching(t) == 0)
			return (0);
		if (t->type == EXPRESSION && ft_check_expression(t) == 0)
			return (0);
		if ((t->type == PIPE || t->type == AND_OPR || t->type == OR_OPR) && (
				ft_has(LEFT, tokens->prev) == 0
				|| ft_has(RIGHT, tokens->next) == 0
			))
			return (0);
		if (ft_is_redirection(t->type) && ft_check_redirection(tokens) == 0)
			return (0);
		if (t->type == SUB_CMD && ft_check_subcommand(tokens) == 0)
			return (0);
		tokens = tokens->next;
	}
	return (1);
}
