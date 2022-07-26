/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:20:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 21:40:06 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list	*ft_search_env(char *var_name)
{
	t_list	*lst;

	lst = g_.env;
	while (lst)
	{
		if (
			(int)ft_strlen(var_name) == ft_strchr(lst->content, '=') - (char *)lst->content
			&& ft_strncmp(var_name, (char *)lst->content, ft_strlen(var_name)) == 0
		)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
