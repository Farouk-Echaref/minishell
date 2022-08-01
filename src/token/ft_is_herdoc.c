/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_herdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:40:13 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 22:26:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"

int	ft_is_herdoc_tree(t_tree *tree)
{
	t_token	*token;

	if (! tree)
		return (0);
	token = ft_get_token_tree(tree);
	if (token->type == SHIFT_LEFT)
		return (1);
	return (0);
}
