/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstflatten_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 01:10:42 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:08:17 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static void	ft_split_token(t_list *node, t_list *target_node)
{
	t_list	*detached;

	detached = ft_lstdetach(node);
	ft_lstpush_list_after(target_node, ft_get_token(node)->value);
	free(detached);
	detached = NULL;
}

t_list	*ft_lstflatten_tokens(t_list *tokens)
{
	t_list	*head;
	t_list	*target;
	t_list	*next_token;
	t_list	*last;

	head = tokens;
	while (tokens)
	{
		target = tokens->prev;
		next_token = tokens->next;
		if (ft_get_token(tokens)->is_list && target)
			ft_split_token(tokens, target);
		else if (ft_get_token(tokens)->is_list)
		{
			head = ft_get_token(tokens)->value;
			last = ft_lstlast(head);
			last->next = tokens->next;
			if (tokens->next)
				tokens->next->prev = last;
		}
		tokens = next_token;
	}
	return (head);
}
