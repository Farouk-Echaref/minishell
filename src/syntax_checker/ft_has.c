/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:05:06 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 02:05:25 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_checker.h"

int	ft_has(t_direction direction, t_list *node)
{
	t_token	*t;

	if (! node)
		return (0);
	t = ft_get_token(node);
	if (t->type == AND_OPR || t->type == OR_OPR || t->type == PIPE)
		return (0);
	if (t->type != WHITE_SPACE)
		return (1);
	if (direction == LEFT)
		return (ft_has(LEFT, node->prev));
	return (ft_has(RIGHT, node->next));
}
