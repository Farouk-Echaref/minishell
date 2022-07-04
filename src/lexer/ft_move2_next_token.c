/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2next_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:34:09 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/01 04:34:32 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

void	ft_move2_next_token(t_lexer *lxr)
{
	while (lxr->content
		&& *lxr->content
		&& ft_get_type_of_char(*lxr->content) == OTHER
	)
		lxr->content++;
}
