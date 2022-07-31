/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:45:58 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/30 03:14:59 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

static int ft_match(const char *pattern, const char *candidate, int p, int c)
{
	if (pattern[p] == '\0') {
		return candidate[c] == '\0';
	} else if (pattern[p] == '*') {
		while (candidate[c] != '\0') {
			if (ft_match(pattern, candidate, p+1, c))
				return 1;
			c++;
		}
		return ft_match(pattern, candidate, p+1, c);
	} else if (pattern[p] != '?' && pattern[p] != candidate[c]) {
		return 0;
	}  else {
		return ft_match(pattern, candidate, p+1, c+1);
	}
}

static t_list	*ft_get_matches(t_list *file_names, t_token *token)
{
	t_list	*matches;
	char	*file_name;

	matches = NULL;
	while (file_names)
	{
		file_name = file_names->content;
		if (ft_match(token->value, file_name, 0, 0))
			ft_lstadd_back(&matches, ft_lstnew(ft_strdup(file_name)));
		file_names = file_names->next;
	}
	return (matches);
}

int	ft_expand_wildcard(t_token *token, int is_redirection)
{
	t_list	*file_names;
	t_list	*matches;
	int		is_ambiguous_redirection;

	is_ambiguous_redirection = 0;
	if (! ft_strchr(token->value, '*') || token->type == DOUB_QUOT || token->type == SING_QUOT)
		return (1);
	file_names = ft_get_file_names();
	matches = ft_get_matches(file_names, token);
	ft_lstclear(&file_names, free);
	if (! matches)
		return (1);
	if (ft_lstsize(matches) > 1 && is_redirection)
		is_ambiguous_redirection = 1;
	token->value = ft_free(token->value);
	token->value = ft_lstjoin_matches(matches);
	token->type = STAR;
	ft_lstclear(&matches, free);
	return (! is_ambiguous_redirection);
}
