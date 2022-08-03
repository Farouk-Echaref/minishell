/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:37:13 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:03:25 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	ft_print_list(t_list *list)
{
	t_token	*token;

	while (list)
	{
		token = list->content;
		if (token->is_list)
			ft_print_tokens_list(token);
		else
			printf("|%s|(%s)\n", token->value, ft_get_type_name(token->type));
		list = list->next;
	}
}

void	ft_print_list_values(t_list *list)
{
	t_token	*token;

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
			continue ;
		}
		printf("%s ", token->value);
		list = list->next;
	}
	if (! list)
		printf("\n");
}

void	ft_print_list_values_reverse(t_list *list)
{
	t_token	*token;

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
			continue ;
		}
		printf("%s ", token->value);
		list = list->prev;
	}
	if (! list)
		printf("\n");
}
