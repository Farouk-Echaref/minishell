/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:33:54 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 14:07:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_expression_list(t_list *tokens)
{
	while (tokens)
	{
		ft_expand_expression(ft_get_token(tokens), NULL);
		tokens = tokens->next;
	}
}
