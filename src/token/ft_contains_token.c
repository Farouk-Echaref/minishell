/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:05:44 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/29 21:07:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	ft_contains_token(t_list *lst, t_type token_type)
{
	while (lst)
	{
		if (ft_get_token_type(lst) == token_type)
			return (1);
		lst = lst->next;
	}
	return (0);
}
