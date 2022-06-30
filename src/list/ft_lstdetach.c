/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:47:19 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/30 03:06:09 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*ft_lstdetach(t_list *el)
{
	t_list	*prev;
	t_list	*next;

	if (! el)
		return NULL;
	prev = el->prev;
	next = el->next;
	el->prev = NULL;
	el->next = NULL;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return (el);
}
