/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_list_after.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:49:16 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/29 00:38:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstpush_list_after(t_list *target, t_list *new_list)
{
	t_list	*next;

	if (! target || ! new_list)
		return ;
	while (new_list)
	{
		next = new_list->next;
		ft_lstpush_after(target, ft_lstdetach(new_list));
		new_list = next;
	}
}
