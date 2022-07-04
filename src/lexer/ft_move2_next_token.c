/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2_next_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:34:09 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/04 10:37:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

void	ft_move2_next_token(t_lexer *lxr)
{
	while (lxr->content
		&& *lxr->content
		&& ft_get_type_of_char(*lxr->content) == OTHER
		&& ! ft_is_var(lxr->content)
	)
		lxr->content++;
}
