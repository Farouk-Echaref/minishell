/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstflatten_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 01:10:42 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/30 01:16:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_list	*ft_lstflatten_tokens(t_list *tokens)
{
	t_list	*head;
	t_list	*detached;
	t_list	*target;
	t_list	*next_token;
	t_list	*last;

	head = tokens;
	while (tokens)
	{
		target = tokens->prev;
		next_token = tokens->next;
		if (ft_get_token(tokens)->is_list && target) {
			detached = ft_lstdetach(tokens);
			ft_lstpush_list_after(target, ft_get_token(tokens)->value);
			free(detached);
			detached = NULL;
		} else if (ft_get_token(tokens)->is_list) {
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
