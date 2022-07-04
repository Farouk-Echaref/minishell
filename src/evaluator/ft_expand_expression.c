/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 19:15:32 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

void	ft_expand_expression_list(t_list *tokens)
{
	while (tokens)
	{
		ft_expand_expression(ft_get_token(tokens));
		tokens = tokens->next;
	}
}

void	ft_merge_tokens(t_token *token)
{
	char	*result;
	t_list	*tokens;
	char	*temp;
	char	*str;

	result = ft_strdup("");
	tokens = token->value;
	while (tokens)
	{
		if (ft_get_token(tokens)->value)
		{
			temp = result;
			str = ft_str(ft_get_token(tokens)->value, ft_get_token(tokens)->length);
			result = ft_strjoin(result, str);
			str = ft_free(str);
			temp = ft_free(temp);
		}
		tokens = tokens->next;
	}
	token->type = EXPRESSION;
	ft_lstclear((t_list **)&token->value, free);
	token->value = result;
	token->is_list = 0;
}

void	ft_expand_expression(t_token *token)
{
	if (token->is_list) {
		ft_expand_expression_list(token->value);
		ft_merge_tokens(token);
	} else if (token->type == SING_QUOT) {
		token->value++;
		token->length -= 2;
	} else if (token->type == DOUB_QUOT) {
		// evalute variables
		token->value++;
		token->length -= 2;
	} else if (token->type == VAR) {
		// evalute variables
	}
}
