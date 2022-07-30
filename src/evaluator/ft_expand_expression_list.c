/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:33:54 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/30 03:23:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_expression_list(t_list *tokens, t_evaluator_data *ev_data, int is_redirection)
{
	while (tokens)
	{
		ft_expand_expression(ft_get_token(tokens), ev_data, 0, is_redirection);
		tokens = tokens->next;
	}
}
