/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_tokens_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:21:07 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 03:41:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_list	*ft_duplicate_tokens_list(const t_list	*tokens)
{
	t_list	*new_list;
	t_token	*new_token;

	if (! tokens)
		return (NULL);
	new_list = NULL;
	while (tokens)
	{
		new_token = ft_duplicate_token((t_token *)tokens->content);
		ft_lstadd_back(&new_list, ft_lstnew(new_token));
		tokens = tokens->next;
	}
	return (new_list);
}
