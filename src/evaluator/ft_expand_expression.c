/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/30 01:41:39 by mzarhou          ###   ########.fr       */
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
	t_token *t;

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

static void	ft_expand_lists(t_list *lst)
{
	while (lst)
	{
		if (ft_get_token(lst)->is_list || ft_get_token_type(lst) == STAR)
			ft_expand_expression(ft_get_token(lst), 1);
		lst = lst->next;
	}
}

void	ft_expand_expression(t_token *token, int from_tree)
{
	char	*str;

	if (token->is_list) {
		ft_expand_expression_list(token->value);
		token->value = ft_lstflatten_tokens(token->value);
		if (ft_contains_token(token->value, WHITE_SPACE)) {
			ft_merge_expressions_wrapper((t_list **)&token->value);
			ft_expand_lists(token->value);
			token->type = STAR;
		} else if (ft_expand_star_list(token))
			return ;
		ft_merge_tokens(token);
	} else if (token->type == DOUB_QUOT) {
		ft_expand_double_qoutes(token);
	} else if (token->type == VAR) {
		str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str);
		str = ft_free(str);
		token->length = ft_strlen(token->value);
		token->is_list = 1;
		token->type = EXPRESSION;
		token->value = ft_split_var(token->value);
		str = ft_free(str);
		if (from_tree)
			ft_expand_expression(token, 1);
	} else if (token->type == STAR) {
		ft_expand_wildcard(token);
	}
	if (! token->is_list)
		token->length = ft_strlen(token->value);
}
