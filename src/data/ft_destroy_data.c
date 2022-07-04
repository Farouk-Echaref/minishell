/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:54:51 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 18:30:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "token/token.h"

void	ft_free_tokens(t_list *tokens)
{
	t_list *next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens);
		tokens = next;
	}
}

void	ft_destroy_data(t_data *data)
{
	t_list	*tokens;
	t_list	*next;

	if (! data)
		return ;

	tokens = data->tokens;
	while (tokens)
	{
		next = tokens->next;
		if (ft_get_token(tokens)->is_list) {
			ft_free_tokens(ft_get_token(tokens)->value);
			ft_get_token(tokens)->value = NULL;
		}
		tokens = next;
	}
	ft_lstclear(&data->tokens, &free);
	ft_tree_clear(&data->tree, &free);
}
