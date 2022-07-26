/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:40:25 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 18:40:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

t_list	*ft_get_file_names()
{
	DIR				*dir;
	struct dirent	*ent;
	t_list			*file_names;

	file_names = NULL;
	if ((dir = opendir (".")) == NULL)
		return (perror (""), file_names);
	while ((ent = readdir (dir)) != NULL)
	{
		if (ent->d_name[0] == '.')
			continue;
		ft_lstadd_back(&file_names, ft_lstnew(ft_strdup(ent->d_name)));
	}
	closedir (dir);
	return (file_names);
}
