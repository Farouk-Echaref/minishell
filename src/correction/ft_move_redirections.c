/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:05:37 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 18:32:16 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"
#include <stdio.h>
#include "utils/utils.h"

t_list	*ft_get_target(t_list *current)
{
	t_list	*tokens;

	if (! current)
		return (NULL);
	tokens = current;
	while (current)
	{
		if (
			ft_get_token_type(current) == AND_OPR
			|| ft_get_token_type(current) == OR_OPR
			|| ft_get_token_type(current) == PIPE
		)
			break ;
		current = current->next;
	}
	if (current)
		return (current->prev);
	return (ft_lstlast(tokens));
}

t_list	*ft_get_list_head(t_list *current)
{
	t_list	*head;

	head = current;
	while (current)
	{
		if (
			(
				ft_get_token(current)->type == EXPRESSION
				|| ft_get_token(current)->type == SING_QUOT
				|| ft_get_token(current)->type == DOUB_QUOT
				|| ft_get_token(current)->type == VAR
			) && (
				current->prev == NULL || ! ft_is_redirection(ft_get_token(current->prev)->type)
			)
		)
			break ;
		current = current->next;
	}
	if (current)
		return (current);
	return (head);
}

t_list	*ft_move_redirections(t_list *current)
{
	t_list	*target;
	t_list	*redir_token;
	t_list	*filename_token;
	t_list	*head;

	head = ft_get_list_head(current);
	while (current && current != head)
	{
		if (ft_is_redirection(ft_get_token_type(current)) && current->next)
		{
			target = ft_get_target(current);
			redir_token = current;
			filename_token = current->next;
			current = current->next->next;
			ft_get_token(filename_token)->is_filename = 1;
			ft_lstpush_after(target, ft_lstdetach(redir_token));
			ft_lstpush_after(redir_token, ft_lstdetach(filename_token));
		}
		if (! current)
			break ;
		current = current->next;
	}
	return (head);
}
