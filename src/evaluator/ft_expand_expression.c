/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 14:01:50 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "lexer/lexer.h"

void	ft_expand_expression(t_token *token, char **argenv)
{
	if (token->is_list) {
		ft_expand_expression_list(token->value, argenv);
		ft_merge_tokens(token);
	} else if (token->type == DOUB_QUOT) {
		ft_expand_double_qoutes(token, argenv);
	} else if (token->type == VAR) {
		char *str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str, argenv);
		token->length = ft_strlen(token->value);
		token->type = EXPRESSION;
		str = ft_free(str);
	}
}
