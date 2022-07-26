/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:33:54 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 22:59:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_expression_list(t_list *tokens)
{
	while (tokens)
	{
		ft_expand_expression_no_star(ft_get_token(tokens));
		tokens = tokens->next;
	}
}
