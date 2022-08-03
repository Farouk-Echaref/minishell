/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:36:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:03:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

static int	ft_list_has_star(t_list *lst)
{
	while (lst)
	{
		if (ft_get_token(lst)->type == STAR)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	ft_match_pattern(t_list *pattern, const char *fname, int c)
{
	char	*pattern_value;

	pattern_value = NULL;
	if (pattern)
		pattern_value = ft_get_token(pattern)->value;
	if (! pattern)
		return (fname[c] == '\0');
	else if (ft_get_token(pattern)->type == STAR)
	{
		while (fname[c] != '\0')
		{
			if (ft_match_pattern(pattern->next, fname, c))
				return (1);
			c++;
		}
		return (ft_match_pattern(pattern->next, fname, c));
	}
	else if (pattern_value[0] != fname[c])
		return (0);
	return (ft_match_pattern(pattern->next, fname, c + 1));
}

static t_list	*ft_get_matches(t_list *file_names, t_list *pattern)
{
	t_list	*result;

	result = NULL;
	while (file_names)
	{
		if (ft_match_pattern(pattern, file_names->content, 0))
			ft_lstadd_back(&result, ft_lstnew(ft_strdup(file_names->content)));
		file_names = file_names->next;
	}
	return (result);
}

int	ft_expand_star_list(t_token *token,
	int is_redirection, int *is_ambiguous_redirection_status)
{
	t_list	*file_names;
	t_list	*matches;
	t_list	*pattern;

	matches = NULL;
	pattern = NULL;
	*is_ambiguous_redirection_status = 0;
	if (! ft_list_has_star(token->value))
		return (0);
	file_names = ft_get_file_names();
	pattern = ft_split_pattern(token->value);
	matches = ft_get_matches(file_names, pattern);
	ft_lstclear(&file_names, free);
	ft_lstclear(&pattern, &ft_free_token);
	if (! matches)
		return (0);
	ft_lstclear((t_list **)&token->value, &ft_free_token);
	token->value = ft_lstjoin_matches(matches);
	token->type = STAR;
	token->is_list = 0;
	if (ft_lstsize(matches) > 1 && is_redirection)
		*is_ambiguous_redirection_status = 1;
	ft_lstclear(&matches, free);
	return (1);
}
