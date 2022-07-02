/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_matching.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:50:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 03:21:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

void	ft_handle_matching(t_lexer *lxr, char c)
{
	char	*matching;

	matching = ft_strchr(lxr->content + 1, c);
	while (
		matching
		&& *matching
		&& ft_get_type_of_char(*matching) != WHITE_SPACE
		&& ft_get_type_of_char(*matching) != PIPE
		&& ft_get_type_of_char(*matching) != AND_OPR
		&& ft_get_type_of_char(*matching) != OR_OPR
	)
		matching++;
	if (matching != NULL)
		ft_move_content(lxr, matching - lxr->content + 1);
	else
		ft_move_content(lxr, 1);
}
