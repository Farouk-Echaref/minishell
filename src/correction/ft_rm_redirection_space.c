/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_redirection_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:43:45 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 13:03:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"
#include "utils/utils.h"

void	ft_rm_redirection_space(t_list *tokens)
{
	t_list	*next;

	while (tokens)
	{
		next = tokens->next;
		if (
			next
			&& ft_is_redirection(ft_get_token(tokens)->type)
			&& ft_get_token(next)->type == WHITE_SPACE
		)
		{
			next = next->next;
			ft_free(ft_lstdetach(tokens->next));
		}
		tokens = next;
	}
}
