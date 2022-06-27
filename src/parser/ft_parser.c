/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 10:10:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft/libft.h"
#include "token/token.h"

t_list	**ft_split_tokens(t_list *tokens, const char* split_by)
{
	// t_token	*token;
	t_list	*token_node;

	split_by = 0;
	if (! tokens)
		return (NULL);
	token_node = tokens;
	return (NULL);
}

t_tree	*ft_parser(t_list *tokens)
{
	t_tree	*tree_root;
	t_list	*token_node;
	t_token	*token;

	if (! tokens)
		return (NULL);
	tree_root = NULL;
	token_node = tokens;
	while (token_node)
	{
		token = token_node->content;
		if (token->length == 2 && (ft_strncmp(token->value, "&&", 2) == 0 || ft_strncmp(token->value, "||", 2) == 0))
		{

		}
		token_node = token_node->next;
	}
	return (NULL);
}
