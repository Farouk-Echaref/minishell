/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_redirection_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:43:45 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 03:36:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"
#include "utils/utils.h"

void	ft_rm_redirection_space(t_list *tokens)
{
	t_list	*next;
	t_list	*temp;

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
			temp = ft_lstdetach(tokens->next);
			ft_free_token(temp->content);
			ft_free(temp);
		}
		tokens = next;
	}
}
