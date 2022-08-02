/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:06:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 00:17:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

void	ft_set_file_names(t_list *tokens)
{
	while (tokens)
	{
		if (ft_is_redirection(ft_get_token_type(tokens)))
			ft_get_token(tokens->next)->is_filename = 1;
		tokens = tokens->next;
	}
}

void	ft_evaluat_herdoc(t_list *node)
{
	t_token		*t;
	const char	*file_name = "/tmp/.heredocument";

	while (node)
	{
		t = ft_get_token(node);
		if (ft_is_herdoc(node) && ft_get_token(node->next)->is_list)
		{
			ft_merge_tokens(ft_get_token(node->next));
			ft_get_token(node->next)->is_herdoc_expr_list = 1;
		}
		if (ft_is_herdoc(node))
		{
			ft_herdoc(node, file_name);
			t->type = REDIR_LEFT;
			t->value = "<";
			t->length = 1;
			ft_get_token(node->next)->value = (void *)file_name;
			ft_get_token(node->next)->length = ft_strlen(file_name);
		}
		node = node->next;
	}
}



void	ft_correct_tokens(t_list **tokens_ptr)
{
	ft_merge_expressions_wrapper(tokens_ptr);
	ft_rm_redirection_space(*tokens_ptr);
	ft_set_file_names(*tokens_ptr);
	ft_evaluat_herdoc(*tokens_ptr);
}
