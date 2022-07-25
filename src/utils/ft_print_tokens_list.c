/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:48:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 15:25:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_tokens_list(t_token *token)
{
	char	*str;
	t_list	*list;

	if (! token)
		return ;
	list = token->value;
	printf("list(%s): ", ft_get_type_name(token->type));
	while (list)
	{
		str = ft_str(ft_get_token(list)->value, ft_get_token(list)->length);
		printf(" |%s(%s)| ", str, ft_get_type_name(ft_get_token(list)->type));
		free(str);
		list = list->next;
	}
	printf("\n");
}
