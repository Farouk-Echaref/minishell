/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 19:26:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "lexer/lexer.h"

void	ft_expand_expression(t_token *token, t_token *right_token)
{
	char	*str;

	if (right_token)
		ft_expand_expression(right_token, NULL);
	else if (token->is_list) {
		ft_expand_expression_list(token->value);
		// ft_expand_star_list(token);
		ft_merge_tokens(token);
	} else if (token->type == DOUB_QUOT) {
		ft_expand_double_qoutes(token);
	} else if (token->type == VAR) {
		str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str);
		token->length = ft_strlen(token->value);
		token->type = EXPRESSION;
		str = ft_free(str);
	}
}
