/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:23:49 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/08 13:09:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	}
}

// #include <stdio.h>
// #include "libft.h"
// #include <string.h>
// int main()
// {
// 	t_list* l = NULL;
// 	t_list* n = ft_lstnew(ft_strdup("OK"));

// 	ft_lstadd_back(&l, n);
// 	if (l == n && !strcmp(l->content, "OK"))
// 	{
// 		printf("test success\n");
// 		return (0);
// 	}
// 	printf("fail\n");
// }
