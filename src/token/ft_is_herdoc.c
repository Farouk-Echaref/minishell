/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_herdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:40:13 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 23:54:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"

int	ft_is_herdoc(t_list *lst)
{
	t_token	*token;

	if (! lst)
		return (0);
	token = ft_get_token(lst);
	if (token->type == SHIFT_LEFT)
		return (1);
	return (0);
}
