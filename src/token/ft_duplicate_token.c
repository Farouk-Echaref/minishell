/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:22:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:42:45 by mzarhou          ###   ########.fr       */
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
	token->type = t->type;
	if (t->is_list)
		token->value = ft_duplicate_tokens_list(t->value);
	else
		token->value = ft_strdup(t->value);
	token->is_list = t->is_list;
	token->is_filename = t->is_filename;
	token->is_herdoc_expr_list = t->is_herdoc_expr_list;
	return (token);
}
