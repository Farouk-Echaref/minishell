/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:37:13 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 15:25:20 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	ft_print_list(t_list *list)
{
	t_token	*token;
	char	*str;

	while (list)
	{
		token = list->content;
		if (token->is_list) {
			ft_print_tokens_list(token);
		} else {
			str = ft_str(token->value, token->length);
			printf("%s(%s)\n", str, ft_get_type_name(token->type));
			free(str);
		}
		list = list->next;
	}
}

void	ft_print_list_values(t_list *list)
{
	t_token	*token;
	char	*str;

	if (!list)
		return ;
	while (list)
	{
		token = list->content;
		if (token->is_list)
		{
			printf("------------------ list start\n");
			ft_print_list(token->value);
			printf("------------------ list end\n");
			list = list->next;
			continue;
		}
		str = ft_str(token->value, token->length);
		printf("%s ", str);
		free(str);
		list = list->next;
	}
	if (! list)
		printf("\n");
}

void	ft_print_list_values_reverse(t_list *list)
{
	t_token	*token;
	char	*str;

	if (!list)
		return ;
	list = ft_lstlast(list);
	while (list)
	{
		token = list->content;
		if (token->is_list)
		{
			printf("------------------ list start\n");
			ft_print_list(token->value);
			printf("------------------ list end\n");
			list = list->next;
			continue;
		}
		str = ft_str(token->value, token->length);
		printf("%s ", str);
		free(str);
		list = list->prev;
	}
	if (! list)
		printf("\n");
}
