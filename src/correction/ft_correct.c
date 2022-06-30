/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 06:49:06 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/30 00:23:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"
#include "libft/libft.h"

t_list	*ft_detach_token(t_list *el)
{
	t_list	*prev;
	t_list	*next;

	if (! el)
		return NULL;
	prev = el->prev;
	next = el->next;
	el->prev = NULL;
	el->next = NULL;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return (el);
}

void	ft_push_after(t_list *target, t_list *new_el)
{
	t_list	*next;

	if (! target || ! new_el)
		return ;
	next = target->next;
	target->next = new_el;
	new_el->prev = target;
	new_el->next = next;
	if (next)
		next->prev = new_el;
}

void	ft_push_before(t_list *target, t_list *new_el)
{
	t_list	*prev;

	if (! target || ! new_el)
		return ;
	prev = target->prev;
	target->prev = new_el;
	new_el->next = target;
	new_el->prev = prev;
	if (prev)
		prev->next = new_el;
}

t_list	*ft_move_expressions(t_list *target)
{
	t_list	*current;
	t_list	*next_backup;
	t_list	*temp;

	if (! target)
		return (NULL);
	((t_token*)target->content)->type = COMMAND;
	current = target->next;
	while (current)
	{
		if (
			ft_get_token_type(current) == AND_OPR
			|| ft_get_token_type(current) == OR_OPR
			|| ft_get_token_type(current) == PIPE
		)
			break;
		else if (ft_get_token_type(current) == EXPRESSION)
		{
			next_backup = current->next;
			temp = ft_detach_token(current);
			ft_push_after(target, temp);
			((t_token*)current->content)->type = COMMAND;
			target = target->next;
			current = next_backup;
		}
		else
			current = current->next;
	}
	return (target->next);
}

void	ft_merge_expressions(t_list *current)
{
	while (current)
	{
		if (ft_get_token_type(current) == EXPRESSION)
		{
			current = ft_move_expressions(current);
			continue;
		}
		current = current->next;
	}
}

void	ft_merge_redirect(t_list* next_item)
{
	t_token	*token;

	if (next_item == NULL)
		return;
	token = next_item->content;
	if (token->type != EXPRESSION)
	{
		next_item = next_item->next;
		if (!next_item)
			return;
	}
	token = next_item->content;
	if (token->type == EXPRESSION)
		token->type = FILE_NAME;
}

void	ft_rearrange_tokens(t_list	*tokens)
{
	t_list	*item;
	t_token	*token;

	if (! tokens)
		return ;
	item = tokens;
	while (item)
	{
		token = item->content;
		if (token->type == REDIR_RIGHT ||
			token->type == REDIR_LEFT  ||
			token->type == SHIFT_LEFT  ||
			token->type == SHIFT_RIGHT)
			ft_merge_redirect(item->next);
		item = item->next;
	}
	ft_merge_expressions(tokens);
}
