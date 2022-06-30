/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:05:37 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/30 03:54:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"
#include <stdio.h>
#include "utils/utils.h"

t_list	*ft_get_target(t_list *current)
{
	t_list	*tokens;

	if (! current)
		return NULL;
	tokens = current;
	while (current)
	{
		if (
			ft_get_token_type(current) == AND_OPR
			|| ft_get_token_type(current) == OR_OPR
			|| ft_get_token_type(current) == PIPE
		)
			break;
		current = current->next;
	}
	if (current)
		return current->prev;
	return ft_lstlast(tokens);
}

t_list	*ft_get_list_head(t_list *current)
{
	while (current)
	{
		if (ft_get_token(current)->type == EXPRESSION && (current->prev == NULL || ft_get_token(current->prev)->type != REDIR_RIGHT))
			break;
		current = current->next;
	}
	return (current);
}

t_list	*ft_move_redirections(t_list *current)
{
	t_list	*target;
	t_list	*redir_token;
	t_list	*filename_token;
	t_list	*head;

	head = ft_get_list_head(current);
	while (current)
	{
		if (! (ft_get_token_type(current) == REDIR_RIGHT && ft_get_token_type(current->next) == EXPRESSION))
		{
			current = current->next;
			continue;
		}
		target = ft_get_target(current);
		redir_token = current;
		filename_token = current->next;
		current = current->next->next;
		ft_get_token(filename_token)->type = FILE_NAME;
		ft_lstdetach(filename_token);
		ft_lstpush_after(target, ft_lstdetach(redir_token));
		ft_lstpush_after(redir_token, ft_lstdetach(filename_token));
	}
	return (head);
}
