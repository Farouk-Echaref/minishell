/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:04:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 21:31:30 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

t_list	*ft_arr_to_list(char **argenv)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	if (! argenv)
		return (NULL);
	i = 0;
	while (argenv[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(argenv[i])));
		i++;
	}
	return (lst);
}
