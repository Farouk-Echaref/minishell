/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:40:25 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:42:36 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

t_list	*ft_get_file_names(void)
{
	DIR				*dir;
	struct dirent	*ent;
	t_list			*file_names;

	file_names = NULL;
	dir = opendir (".");
	if (dir == NULL)
		return (perror (""), file_names);
	ent = readdir (dir);
	while (ent != NULL)
	{
		if (ent->d_name[0] != '.')
			ft_lstadd_back(&file_names, ft_lstnew(ft_strdup(ent->d_name)));
		ent = readdir (dir);
	}
	closedir (dir);
	return (file_names);
}
