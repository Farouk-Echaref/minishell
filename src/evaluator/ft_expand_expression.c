/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/29 00:43:37 by mzarhou          ###   ########.fr       */
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

t_list	*ft_lst_flatten(t_list *tokens)
{
	t_list	*head;
	t_list	*detached;
	t_list	*target;
	t_list	*next_token;
	t_list	*last;

	head = tokens;
	while (tokens)
	{
		target = tokens->prev;
		next_token = tokens->next;
		if (ft_get_token(tokens)->is_list && target) {
			detached = ft_lstdetach(tokens);
			ft_lstpush_list_after(target, ft_get_token(tokens)->value);
			detached = ft_free(detached);
		} else if (ft_get_token(tokens)->is_list) {
			head = ft_get_token(tokens)->value;
			last = ft_lstlast(head);
			last->next = tokens->next;
			tokens->prev = last;
		}
		tokens = next_token;
	}
	return (head);
}

static	void	ft_expand(t_token *token, t_token *right_token, int from_tree)
{
	char	*str;

	if (right_token)
		ft_expand(right_token, NULL, 1);
	else if (token->is_list) {
		ft_expand_expression_list(token->value);
		token->value = ft_lst_flatten(token->value);
		// ft_print_list(token->value);
		// printf("-----------------\n");
		ft_expand_star_list(token);
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
			ft_expand(token, NULL, 1);
	} else if (token->type == STAR && from_tree) {
		ft_expand_wildcard(token);
	}
}

void	ft_expand_expression(t_token *token, t_token *right_token)
{
	ft_expand(token, right_token, 1);
}

void	ft_expand_expression_from_list(t_token *token)
{
	ft_expand(token, NULL, 0);
}
