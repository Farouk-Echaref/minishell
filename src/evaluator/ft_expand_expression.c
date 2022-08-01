/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 05:09:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "lexer/lexer.h"

static t_list	*ft_split_var(char *var_value)
{
	t_lexer	*lxr;
	t_data	data;
	t_list	*tokens;
	t_token	*t;

	data.tokens = NULL;
	data.tree = NULL;
	lxr = ft_init_lexer(var_value);
	data.tokens = ft_lexer(lxr);
	tokens = data.tokens;
	while (tokens)
	{
		t = ft_get_token(tokens);
		if (t->type != VAR && t->type != STAR && t->type != WHITE_SPACE)
			t->type = EXPRESSION;
		t->value = ft_str(t->value, t->length);
		tokens = tokens->next;
	}
	ft_destroy_lexer(lxr);
	var_value = ft_free(var_value);
	return (data.tokens);
}

static void	ft_expand_lists(t_list *lst,
	t_evaluator_data *ev_data, int is_redirection)
{
	while (lst)
	{
		if (ft_get_token(lst)->is_list || ft_get_token_type(lst) == STAR)
			ft_expand_expression(ft_get_token(lst), ev_data, 1, is_redirection);
		lst = lst->next;
	}
}

void	ft_ambiguous_redirection(t_evaluator_data *ev_data)
{
	ft_error_message("*", AMBIGUOUS_MESSAGE);
	ev_data->ok = 0;
	g_.exit_status = 1;
}

void	ft_expand_lst(t_token *token,
	t_evaluator_data *ev_data, int is_redirection)
{
	int		is_ambiguous_redirection;

	ft_expand_expression_list(token->value, ev_data, is_redirection);
	token->value = ft_lstflatten_tokens(token->value);
	if (ft_contains_token(token->value, WHITE_SPACE))
		token->type = STAR;
	if (ev_data->expand_star && ft_contains_token(token->value, WHITE_SPACE))
	{
		ft_merge_expressions_wrapper((t_list **)&token->value);
		ft_expand_lists(token->value, ev_data, is_redirection);
	}
	else if (
		ev_data->expand_star
		&& ft_expand_star_list(token, is_redirection, &is_ambiguous_redirection)
	)
	{
		if (is_ambiguous_redirection)
			ft_ambiguous_redirection(ev_data);
		return ;
	}
	ft_merge_tokens(token);
}

void	ft_expand_expression(t_token *token,
	t_evaluator_data *ev_data, int from_tree, int is_redirection)
{
	char	*str;

	if (! ev_data->ok)
		return ;
	if (token->is_list)
		ft_expand_lst(token, ev_data, is_redirection);
	else if (token->type == DOUB_QUOT)
		ft_expand_double_qoutes(token);
	else if (token->type == VAR)
	{
		str = ft_str(token->value, token->length);
		token->value = ft_assign_free(&str, ft_evaluate_var(str));
		token->length = ft_strlen(token->value);
		if (ft_strcmp(token->value, "") == 0)
			return ;
		token->is_list = 1;
		token->type = EXPRESSION;
		token->value = ft_split_var(token->value);
		if (from_tree)
			ft_expand_expression(token, ev_data, 1, is_redirection);
	}
	else if (token->type == STAR && from_tree
		&& ev_data->expand_star
		&& ! ft_expand_wildcard(token, is_redirection))
		ft_ambiguous_redirection(ev_data);
}
