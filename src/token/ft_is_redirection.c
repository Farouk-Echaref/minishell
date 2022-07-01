/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:05:26 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/01 01:05:45 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token/token.h"

int	ft_is_redirection(t_type token_type)
{
	if (
		token_type == REDIR_LEFT
		|| token_type == REDIR_RIGHT
		|| token_type == SHIFT_LEFT
		|| token_type == SHIFT_RIGHT
	)
		return (1);
	return (0);
}
