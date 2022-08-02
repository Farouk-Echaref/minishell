/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:22:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 20:52:53 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*ft_duplicate_token(const t_token *t)
{
	t_token	*token;

	if (! t)
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	if (! token)
		exit(1);
	token->length = t->length;
	token->type = t->type;
	token->value = t->value;
	token->is_list = t->is_list;
	token->is_filename = t->is_filename;
	return (token);
}
