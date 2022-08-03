/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:48:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:01:50 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_tokens_list(t_token *token)
{
	t_list	*list;

	if (! token)
		return ;
	list = token->value;
	printf("list(%s): ", ft_get_type_name(token->type));
	while (list)
	{
		printf(" |%s(%s)| ",
			ft_get_token(list)->value,
			ft_get_type_name(ft_get_token(list)->type));
		list = list->next;
	}
	printf("\n");
}
