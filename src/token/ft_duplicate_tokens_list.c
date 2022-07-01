/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_tokens_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:21:07 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 10:31:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_list	*ft_duplicate_tokens_list(const t_list	*tokens)
{
	t_list	*new_list;
	t_token	*content;

	if (! tokens)
		return (NULL);
	new_list = NULL;
	while (tokens)
	{
		content = ft_duplicate_token((t_token *)tokens->content);
		ft_lstadd_back(&new_list, ft_lstnew(content));
		tokens = tokens->next;
	}
	return (new_list);
}
