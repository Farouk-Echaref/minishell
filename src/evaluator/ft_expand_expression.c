/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/28 21:36:30 by mzarhou          ###   ########.fr       */
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

static	void	ft_expand(t_token *token, t_token *right_token, int expand_star)
{
	char	*str;

	if (right_token)
		ft_expand(right_token, NULL, 1);
	else if (token->is_list) {
		ft_expand_expression_list(token->value);
		ft_expand_star_list(token);
		ft_merge_tokens(token);
	} else if (token->type == DOUB_QUOT) {
		ft_expand_double_qoutes(token);
	} else if (token->type == VAR) {
		str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str);
		token->length = ft_strlen(token->value);
		token->is_list = 1;
		token->type = EXPRESSION;
		token->value = ft_split_var(token->value);
		str = ft_free(str);
		ft_expand(token, NULL, 1);
	} else if (token->type == STAR && expand_star) {
		ft_expand_wildcard(token);
	}
}

void	ft_expand_expression(t_token *token, t_token *right_token)
{
	ft_expand(token, right_token, 1);
}

void	ft_expand_expression_no_star(t_token *token)
{
	ft_expand(token, NULL, 0);
}
