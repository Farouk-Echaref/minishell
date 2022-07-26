/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 14:59:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "lexer/lexer.h"

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
		token->type = EXPRESSION;
		str = ft_free(str);
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
