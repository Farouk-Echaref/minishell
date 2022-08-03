/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:06:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 02:54:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

static void	ft_herdoc_token_list(t_token *t)
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
	t->value = result;
	t->is_list = 0;
	t->length = ft_strlen(t->value);
}

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
	t_token		*next_token;
	char		*file_name;
	int			file_count;

	file_count = 0;
	while (node)
	{
		t = ft_get_token(node);
		if (ft_is_herdoc(node) && ft_get_token(node->next)->is_list)
		{
			ft_herdoc_token_list(ft_get_token(node->next));
			ft_get_token(node->next)->is_herdoc_expr_list = 1;
		}
		if (ft_is_herdoc(node))
		{
			next_token = ft_get_token(node->next);
			file_name = ft_herdoc(node, file_count++);
			t->type = REDIR_LEFT;
			t->value = "<";
			t->length = 1;
			next_token->value = file_name;
			next_token->length = ft_strlen(file_name);
			next_token->type = EXPRESSION;
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
