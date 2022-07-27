/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token_no_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:45:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 23:00:02 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"
#include "utils/utils.h"

void	ft_free_token_no_value(void *tree_content)
{
	t_token	*token;

	token = tree_content;
	if (! token)
		return ;
	if (token->is_list)
		ft_lstclear((t_list **)&token->value, &ft_free_token_no_value);
	token->value = NULL;
	token = ft_free(token);
}
