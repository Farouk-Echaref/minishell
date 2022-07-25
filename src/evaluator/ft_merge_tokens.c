/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:28:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 21:16:45 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_merge_tokens(t_token *token)
{
	char	*result;
	t_list	*tokens;
	char	*temp;
	char	*str;

	if (! token->is_list)
		return ;
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
	ft_lstclear((t_list **)&token->value, ft_free_token);
	token->value = ft_free(token->value);
	token->value = result;
	token->is_list = 0;
}
