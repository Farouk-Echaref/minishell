/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:27:18 by fech-cha          #+#    #+#             */
/*   Updated: 2022/08/02 20:53:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*ft_new_token(void *value, t_type type, int length)
{
	t_token	*t;

	t = malloc(sizeof(t_token));
	if (! t)
		exit(1);
	t->length = length;
	t->type = type;
	t->value = value;
	t->is_list = 0;
	t->is_filename = 0;
	t->is_herdoc_expr_list = 0;
	return (t);
}
