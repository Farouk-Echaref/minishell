/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:23:49 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/26 05:58:57 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd_back(t_list **lst_ptr, t_list *new)
{
	t_list	*lst;

	if (!lst_ptr)
		return ;
	if (!*lst_ptr)
		*lst_ptr = new;
	else
	{
		lst = *lst_ptr;
		while (lst->next != 0)
			lst = lst->next;
		lst->next = new;
		new->prev = lst;
	}
}
