/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:45:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 22:59:52 by mzarhou          ###   ########.fr       */
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
	if (token->is_list)
		ft_lstclear((t_list **)&token->value, &ft_free_token);
	token->value = ft_free(token->value);
	token = ft_free(token);
}
