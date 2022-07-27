/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:45:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/27 17:42:42 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	ft_cleanup_token(t_token *token)
{
	if (token->type == SING_QUOT || token->type == DOUB_QUOT || token->type == SUB_CMD) {
		token->value++;
		token->length -= 2;
	} else if (token->type == VAR) {
		token->value++;
		token->length--;
	}
	token->value = ft_str(token->value, token->length);
}
