/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/28 16:16:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "lexer/lexer.h"

int	ft_should_split_var(char *var_value)
{
	char	**arr;

	if (! var_value)
		return (0);
	arr = ft_split(var_value, ' ');
	if (ft_arr_size(arr) > 1)
		return (ft_arr_free(arr), 1);
	return (ft_arr_free(arr), 0);
}

t_list	*ft_split_var(char *var_value)
{
	t_lexer	*lxr;
	t_data	data;
	t_list	*tokens;

	data.tokens = NULL;
	data.tree = NULL;
	lxr = ft_init_lexer(var_value);
	data.tokens = ft_lexer(lxr);
	ft_correct_tokens(&data.tokens);
	ft_destroy_lexer(lxr);
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
		str = ft_free(str);
		token->length = ft_strlen(token->value);
		token->type = EXPRESSION;
		if (ft_should_split_var(token->value)) {
			token->is_list = 1;
			token->value = ft_split_var(token->value);
		}
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
