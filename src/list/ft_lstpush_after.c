/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:37 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/01 01:08:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstpush_after(t_list *target, t_list *new_el)
{
	t_list	*next;

	if (! target || ! new_el)
		return ;
	next = target->next;
	target->next = new_el;
	new_el->prev = target;
	new_el->next = next;
	if (next)
		next->prev = new_el;
}
