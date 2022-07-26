/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_expressions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:12:52 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 15:36:29 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"
#include "list/list.h"
#include "utils/utils.h"

static int	ft_check_expression(t_list *tokens)
{
	t_type token_type;

	if (! tokens)
		return (0);
	token_type = ft_get_token_type(tokens);
	if (
		token_type == EXPRESSION
		|| token_type == SING_QUOT
		|| token_type == DOUB_QUOT
		|| token_type == VAR
		|| token_type == STAR
	)
		return (1);
	return (0);
}

static int	ft_calc_length(t_list *tokens)
{
	int	len;

	len = 0;
	while (tokens)
	{
		if (ft_get_token(tokens))
			len += ft_get_token(tokens)->length;
		tokens = tokens->next;
	}
	return (len);
}

static t_list	*ft_next_token(t_list *tokens)
{
	while (ft_check_expression(tokens))
		tokens = tokens->next;
	return (tokens);
}

static t_list	*ft_merge_expressions(t_list *tokens)
{
	t_list	*value;
	t_list	*next;
	t_list	*detached_el;
	t_token	*new_token;

	value = NULL;
	while (ft_check_expression(tokens)) {
		next = tokens->next;
		detached_el = ft_lstdetach(tokens);
		ft_lstadd_back(&value , detached_el);
		tokens = next;
	}
	new_token = ft_new_token(value, EXPRESSION, ft_calc_length(value));
	new_token->is_list = 1;
	return (ft_lstnew(new_token));
}

void	ft_merge_expressions_wrapper(t_list **tokens_ptr)
{
	t_list	*new_token;
	t_list	*tokens;
	t_list	*next_token;
	t_list	*prev;

	if (! tokens_ptr || ! *tokens_ptr)
		return ;
	tokens = *tokens_ptr;
	while (tokens)
	{
		if (! ft_check_expression(tokens) || ! ft_check_expression(tokens->next))
		{
			tokens = tokens->next;
			continue;
		}
		next_token = ft_next_token(tokens);
		prev = tokens->prev;
		new_token = ft_merge_expressions(tokens);
		if (prev) {
			ft_lstpush_after(prev, new_token);
		} else {
			*tokens_ptr = new_token;
			(*tokens_ptr)->next = next_token;
		}
		tokens = next_token;
	}
}
