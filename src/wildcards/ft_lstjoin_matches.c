/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin_matches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:41:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

char	*ft_lstjoin_matches(t_list *lst)
{
	char	*result;
	char	*result_item;
	char	*result_item_space;

	result = ft_strdup("");
	while (lst)
	{
		result_item = ft_strjoin(result, lst->content);
		if (lst->next)
			result_item_space = ft_strjoin(result_item, " ");
		result = ft_free(result);
		if (lst->next)
		{
			result = result_item_space;
			result_item = ft_free(result_item);
		}
		else
			result = result_item;
		lst = lst->next;
	}
	return (result);
}
