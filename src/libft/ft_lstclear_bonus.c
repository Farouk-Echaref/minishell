/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:40:00 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/08 18:51:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **list_ptr, void (*del)(void*))
{
	t_list	*next_el;

	if (!list_ptr)
		return ;
	while (*list_ptr)
	{
		next_el = (*list_ptr)->next;
		ft_lstdelone(*list_ptr, del);
		*list_ptr = next_el;
	}
	*list_ptr = 0;
}
