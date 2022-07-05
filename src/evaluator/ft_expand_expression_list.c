/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression_list.C                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:33:54 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:34:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_expression_list(t_list *tokens, char **argenv)
{
	while (tokens)
	{
		ft_expand_expression(ft_get_token(tokens), argenv);
		tokens = tokens->next;
	}
}
