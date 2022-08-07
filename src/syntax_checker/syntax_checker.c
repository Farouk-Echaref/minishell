/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:25:09 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/07 02:14:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_checker/syntax_checker.h"

int	ft_check_subcommand(t_list *node)
{
	t_lexer	*lxr;
	t_data	data;
	int		result;

	data.tokens = NULL;
	data.tree = NULL;
	if (! node || ft_has(LEFT, node->prev) == 1)
		return (0);
	lxr = ft_init_lexer(
			ft_get_token(node)->value
			);
	data.tokens = ft_lexer(lxr);
	result = ft_check_syntax(data.tokens);
	ft_destroy_lexer(lxr);
	ft_lstclear(&data.tokens, &ft_free_token);
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

int	ft_check_syntax(t_list *tokens)
{
	t_token	*t;

	while (tokens)
	{
		t = ft_get_token(tokens);
		if (! t->is_valid)
			return (0);
		if (t->type == EXPRESSION && ft_strchr(t->value, '\\'))
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
