/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:36:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 19:26:08 by mzarhou          ###   ########.fr       */
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

static int	ft_token_match(t_list *node, char *file_name)
{
	(void)file_name;

	if (node->prev && ft_get_token(node->prev)->type == STAR)
	{

	} else {

	}
	return (0);
}

static int	ft_tokens_match(t_list *tokens, char *file_name)
{
	while (tokens)
	{
		if (! ft_token_match(tokens, file_name))
			return (0);
		tokens = tokens->next;
	}
	return (1);
}

void	ft_expand_star_list(t_token *token)
{
	t_list	*file_names;
	t_list	*matches;

	if (! ft_list_has_star(token->value))
		return ;
	file_names = ft_get_file_names();
	matches = NULL;
	while (file_names)
	{
		if (ft_tokens_match(token->value, file_names->content))
			ft_lstadd_back(&matches, ft_lstnew(ft_strdup(file_names->content)));
		file_names = file_names->next;
	}
	if (! matches)
		return ;
	token->type = STAR;
	token->value = ft_lstjoin_matches(matches);
	token->is_list = 0;
	ft_lstclear(&matches, free);
	ft_lstclear(&file_names, free);
}
