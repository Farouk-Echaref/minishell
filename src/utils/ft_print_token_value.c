/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:58:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:00:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_print(t_token *token, int with_newline)
{
	printf("%s", token->value);
	if (with_newline)
		printf("\n");
}

void	ft_print_token_value(t_token *token)
{
	ft_print(token, 0);
}

void	ft_print_token_value_ln(t_token *token)
{
	ft_print(token, 1);
}
