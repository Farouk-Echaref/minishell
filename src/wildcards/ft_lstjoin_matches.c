/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin_matches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 18:42:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

char	*ft_lstjoin_matches(t_list *lst)
{
	char	*result;
	char	*temp;

	result = ft_strdup("");
	while (lst)
	{
		temp = ft_strjoin(result, lst->content);
		temp = ft_strjoin(temp, " ");
		result = ft_free(result);
		result = temp;
		lst = lst->next;
	}
	return (result);
}
