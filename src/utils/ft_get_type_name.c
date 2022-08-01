/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 03:12:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:12:26 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*ft_get_name(t_type t)
{
	if (t == WHITE_SPACE)
		return ("SPACE");
	if (t == REDIR_RIGHT)
		return ("REDR");
	if (t == REDIR_LEFT)
		return ("REDL");
	if (t == SHIFT_LEFT)
		return ("SHL");
	if (t == SHIFT_RIGHT)
		return ("SHR");
	if (t == AND_OPR)
		return ("AND");
	if (t == OR_OPR)
		return ("OR");
	return (NULL);
}

char	*ft_get_type_name(t_type t)
{
	if (ft_get_name(t))
		return (ft_get_name(t));
	if (t == STAR)
		return ("STAR");
	if (t == SUB_CMD)
		return ("SUB_CMD");
	if (t == SING_QUOT)
		return ("SING_Q");
	if (t == DOUB_QUOT)
		return ("DOUB_Q");
	if (t == PIPE)
		return ("PIPE");
	if (t == VAR)
		return ("VAR");
	if (t == EXPRESSION)
		return ("EXPR");
	return ("OTHER");
}
