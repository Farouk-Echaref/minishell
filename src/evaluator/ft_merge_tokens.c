/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:28:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:55:05 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_merge_tokens(t_token *t)
{
	char	*result;
	t_list	*tokens;
	char	*str;

	if (! t->is_list)
		return ;
	result = ft_strdup("");
	tokens = t->value;
	while (tokens)
	{
		if (ft_get_token(tokens)->value)
		{
			str = ft_str(ft_get_token(tokens)->value,
					ft_get_token(tokens)->length);
			result = ft_assign_free(&result, ft_strjoin(result, str));
			str = ft_free(str);
		}
		tokens = tokens->next;
	}
	if (t->type != STAR)
		t->type = EXPRESSION;
	ft_lstclear((t_list **)&t->value, ft_free_token);
	t->value = result;
	t->is_list = 0;
	t->length = ft_strlen(t->value);
}
