/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matches.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:43:03 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 18:43:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

t_list	*ft_get_matches(t_list *file_names, t_token *token)
{
	t_list	*matches;

	matches = NULL;
	while (file_names)
	{
		if (ft_match(token->value, file_names->content, 0, 0))
			ft_lstadd_back(&matches, ft_lstnew(ft_strdup(file_names->content)));
		file_names = file_names->next;
	}
	return (matches);
}
