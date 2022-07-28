/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:28:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/28 21:01:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_merge_tokens(t_token *t)
{
	char	*result;
	t_list	*tokens;
	char	*temp;
	char	*str;
	if (! t->is_list)
		return ;
	result = ft_strdup("");
	tokens = t->value;
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
	t->type = EXPRESSION;
	ft_lstclear((t_list **)&t->value, ft_free_token);
	t->value = ft_free(t->value);
	t->value = result;
	t->is_list = 0;
}
