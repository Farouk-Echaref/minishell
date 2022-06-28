/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commandify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:06:43 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/28 02:12:08 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token/token.h"
#include "libft/libft.h"

void	ft_merge_expressions(t_list *list)
{
	t_list	*item;
	t_list	*temp;
	t_token	*token;
	int		length;

	if (! list)
		return ;
	item = list->next;
	if (item != NULL)
		token = item->content;
	length = 0;
	while (item)
	{
		token = item->content;
		if (token->type != EXPRESSION && token->type != WHITE_SPACE && token->type != DOUB_QUOT && token->type != SING_QUOT)
			break;
		length += token->length;
		temp = item;
		item = item->next;
		free(token);
		free(temp);
	}
	token = list->content;
	token->length += length;
	token->type = COMMAND;
	list->next = item;
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

void	ft_commandify(t_list	*tokens)
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
		else if (token->type == EXPRESSION)
			ft_merge_expressions(item);
		item = item->next;
	}
}
