/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commandify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:06:43 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 22:21:48 by mzarhou          ###   ########.fr       */
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
	if (! item)
		return ;
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
		if (token->type == EXPRESSION)
			ft_merge_expressions(item);
		item = item->next;
	}
}
