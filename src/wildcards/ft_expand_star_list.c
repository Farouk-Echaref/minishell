/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:36:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 16:57:15 by mzarhou          ###   ########.fr       */
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

char	*ft_char_helper(char c)
{
	char *result;

	result = (char *)malloc(2);
	result[0] = c;
	result[1] = 0;
	return (result);
}

static t_list	*ft_split_pattern(t_list *lst)
{
	t_list *result;
	t_token	*token;
	char	*s;

	result = NULL;
	while (lst)
	{
		if (ft_get_token(lst)->type == STAR) {
			ft_lstadd_back(&result, ft_lstnew(ft_duplicate_token(lst->content)));
		} else {
			s = ft_get_token(lst)->value;
			while (s && *s)
			{
				token = ft_new_token(ft_char_helper(*s), EXPRESSION, 1);
				ft_lstadd_back(&result, ft_lstnew(token));
				s++;
			}
		}
		lst = lst->next;
	}
	ft_print_list(lst);
	return (result);
}


static int ft_match_pattern(t_list *pattern, const char *candidate, int c)
{
	char	*pattern_value;

	pattern_value = NULL;
	if (pattern)
		pattern_value = ft_get_token(pattern)->value;
	if (! pattern) {
		return candidate[c] == '\0';
	} else if (ft_get_token(pattern)->type == STAR) {
		while (candidate[c] != '\0') {
			if (ft_match_pattern(pattern->next, candidate, c))
				return 1;
			c++;
		}
		return ft_match_pattern(pattern->next, candidate, c);
	} else if (pattern_value[0] != '?' && pattern_value[0] != candidate[c]) {
		return 0;
	}  else {
		return ft_match_pattern(pattern->next, candidate, c+1);
	}
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

void	ft_expand_star_list(t_token *token)
{
	t_list	*file_names;
	t_list	*matches;
	t_list	*pattern;

	if (! ft_list_has_star(token->value))
		return ;
	file_names = ft_get_file_names();
	pattern = ft_split_pattern(token->value);
	matches = ft_get_matches(file_names, pattern);
	ft_lstclear(&file_names, free);
	ft_lstclear(&pattern, free);
	if (! matches)
		return ;
	token->type = STAR;
	token->value = ft_lstjoin_matches(matches);
	((char *)token->value)[ft_strlen(token->value) - 1] = 0;
	token->is_list = 0;
	ft_lstclear(&matches, free);
}
