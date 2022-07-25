/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:45:58 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 22:20:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

void	ft_expand_wildcard(t_token *token)
{
	t_list	*file_names;
	t_list	*matches;

	if (! ft_strchr(token->value, '*') || token->type == DOUB_QUOT || token->type == SING_QUOT)
		return ;
	file_names = ft_get_file_names();
	matches = ft_get_matches(file_names, token);
	ft_lstclear(&file_names, free);
	if (! matches)
		return ;
	token->value = ft_lstjoin_matches(matches);
	token->type = STAR;
	ft_lstclear(&matches, free);
}
