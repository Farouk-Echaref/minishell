/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:49:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 23:08:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*ft_new_line(char *var_name, char *old_value, char *current_value, int concat)
{
	char	*new_value;

	new_value = NULL;
	if (concat && old_value)
		new_value = ft_strjoin(old_value, current_value);
	else if (current_value)
		new_value = ft_strdup(current_value);
	return (ft_make_env_line(var_name, new_value));
}

static void	*ft_remove_line(t_list *line)
{
	if (! line)
		return (NULL);
	line->content = ft_free(line->content);
	line = ft_free(ft_lstdetach(line));
	return (NULL);
}

void	ft_add_env(char *var_name, char *value, int concat)
{
	char	*line;
	t_list	*old_line;
	char	*old_value;

	if (! var_name)
		return ;
	old_value = NULL;
	old_line = ft_search_env(var_name);
	if (old_line)
		old_value = ft_var_value(old_line->content);
	if (! value && old_line)
		return (free(old_value));
	old_line = ft_remove_line(old_line);
	line = ft_new_line(var_name, old_value, value, concat);
	ft_lstadd_back(&g_.env, ft_lstnew(line));
	old_value = ft_free(old_value);
}
