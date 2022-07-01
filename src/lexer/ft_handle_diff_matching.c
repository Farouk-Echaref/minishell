/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_diff_matching.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/01 01:51:25 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

void	ft_handle_diff_matching(
	t_lexer *lxr, char opening_match, char closing_match)
{
	int			i;
	const char	*s;

	i = 1;
	s = lxr->content + 1;
	while (s && *s)
	{
		if (*s == opening_match)
			i++;
		else if (*s == closing_match)
			i--;
		if (i == 0)
			return (ft_move_content(lxr, s - lxr->content + 1));
		s++;
	}
	ft_move_content(lxr, 1);
}
