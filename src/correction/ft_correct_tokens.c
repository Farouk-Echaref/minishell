/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:06:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 05:29:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

static void	ft_set_file_names(t_list *tokens)
{
	while (tokens)
	{
		if (ft_is_redirection(ft_get_token_type(tokens)))
			ft_get_token(tokens->next)->is_filename = 1;
		tokens = tokens->next;
	}
}

static void	ft_evaluat_herdoc(t_list *node)
{
	t_token		*t;
	char		*file_name;
	int			file_count;

	file_count = 0;
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
			file_name = ft_herdoc(node, file_count++);
			t->type = REDIR_LEFT;
			t->value = ft_assign_free((char **)&t->value, ft_strdup("<"));
			t = ft_get_token(node->next);
			t->value = ft_assign_free(
					(char **)&t->value, file_name);
			t->type = EXPRESSION;
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
