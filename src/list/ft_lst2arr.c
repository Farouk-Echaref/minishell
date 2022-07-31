/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:12:14 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 00:19:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list/list.h"
#include "libft/libft.h"
#include <stdlib.h>

char	**ft_lst2arr(t_list *lst)
{
	int		lst_size;
	char	**result;
	int		i;

	if (! lst)
		return (NULL);
	lst_size = ft_lstsize(lst);
	result = (char **)malloc(lst_size * sizeof(char *) + 1);
	i = 0;
	while (lst)
	{
		result[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	result[i] = 0;
	return (result);
}
