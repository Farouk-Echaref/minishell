/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:45:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 14:46:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"
#include "utils/utils.h"

void	ft_free_token(void *tree_content)
{
	t_token	*token;

	token = tree_content;
	if (! token)
		return ;
	token->value = ft_free(token->value);
	token = ft_free(token);
}
