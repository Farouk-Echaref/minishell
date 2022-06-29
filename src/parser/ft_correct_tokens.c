/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:47:52 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/29 05:40:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token/token.h"
#include "utils/utils.h"
#include <stdio.h>

void	ft_lstadd_back_token(t_list **lst_ptr, t_list *new)
{
	t_list	*last ;

	if (! lst_ptr || ! new)
		return ;
	if (! *lst_ptr) {
		*lst_ptr = new;
	} else {
		last = ft_lstlast(*lst_ptr);
		last->next = new;
	}
}

const char	*ft_get_token_value(t_list *lst)
{
	if (! lst)
		return (NULL);
	t_token *token = lst->content;
	return (token->value);
}

int	ft_check_token(t_list *el)
{
	t_type	token_type;

	if (! el)
		return (1);
	token_type = ft_get_token_type(el);
	if (
		token_type == REDIR_LEFT
		|| token_type == REDIR_RIGHT
		|| token_type == SHIFT_LEFT
		|| token_type == SHIFT_RIGHT
	)
		return (0);
	return (2);
}

int	ft_check_space(t_list *el)
{
	if (! el)
		return (1);
	if (! el->next)
		return (2);
	if (ft_get_token_type(el->next) == WHITE_SPACE)
		return (0);
	return (3);
}

void	ft_detach_elements(t_list **tokens_list_ptr, t_list *r_start, int nb_items)
{
	t_list	*start;
	t_list	*end;
	t_list	*r_end;

	r_end = NULL;
	if (! r_start || ! tokens_list_ptr)
		return ;

	start = r_start->prev;
	r_end = r_start;
	while (--nb_items > 0)
		r_end = r_end->next;
	end = r_end->next;

	// detach elemnents
	r_start->prev = NULL;
	r_end->next = NULL;
	if (start)
		start->next = end;
	if (end)
		end->prev = start;

	// if list head changed
	if (! start)
		*tokens_list_ptr = end;
}

int	ft_redirection_exist(t_list	*tokens_list)
{
	while (tokens_list)
	{
		if (ft_check_token(tokens_list) == 0)
			return (0);
		tokens_list = tokens_list->next;
	}
	return (1);
}

void	ft_correct_tokens_rec(t_list **tokens_list_ptr, t_list	**redirections_ptr)
{
	t_list	*el;
	int		nb_items;

	if (! tokens_list_ptr || ! *tokens_list_ptr)
		return ;
	el = *tokens_list_ptr;
	while (el)
	{
		nb_items = 2;
		if (ft_check_token(el) != 0)
		{
			el = el->next;
			continue;
		}
		if (ft_check_space(el) == 0)
			nb_items = 3;
		ft_lstadd_back_token(redirections_ptr, el);
		ft_detach_elements(tokens_list_ptr, el, nb_items);
		break;
	}
	if (ft_redirection_exist(*tokens_list_ptr) == 0)
		ft_correct_tokens_rec(tokens_list_ptr, redirections_ptr);
}

void	ft_correct_prev(t_list *list)
{
	if (! list)
		return ;
	list->prev = NULL;
	while (list->next)
	{
		list->next->prev = list;
		list = list->next;
	}
}

void	ft_correct_tokens(t_list **tokens_list_ptr)
{
	if (! tokens_list_ptr || ! *tokens_list_ptr)
		return ;
	t_list	*redirections = NULL;
	ft_correct_tokens_rec(tokens_list_ptr, &redirections);
	ft_lstadd_back(tokens_list_ptr, redirections);
	ft_correct_prev(*tokens_list_ptr);
}
