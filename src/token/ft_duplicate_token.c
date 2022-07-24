/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:22:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 16:07:16 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*ft_duplicate_token(const t_token *t)
{
	t_token	*token;

	if (! t)
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	token->length = t->length;
	token->type = t->type;
	token->value = t->value;
	token->is_list = t->is_list;
	return (token);
}
