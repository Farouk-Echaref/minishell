/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 11:56:40 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token/token.h"
#include <stdio.h>

t_tree	*ft_parser(t_list *tokens)
{
	t_tree	*tree_root;
	t_list	*token_node;
	t_token	*token;
	t_list	*next_token_node;

	if (! tokens)
		return (NULL);
	tokens = ft_duplicate_tokens_list(tokens);
	tree_root = NULL;
	next_token_node = NULL;
	token_node = tokens;
	int	found = 0;
	while (token_node)
	{
		token = token_node->content;
		if (token->type == AND_OPR || token->type == OR_OPR)
		{
			tree_root =	ft_new_tree_node(ft_duplicate_token(token));
			next_token_node = token_node->next;
			token_node->prev->next = NULL;
			found = 1;
			break;
		}
		token_node = token_node->next;
	}
	if (! found)
	{
		token_node = tokens;
		while (token_node)
		{
			token = token_node->content;
			if (token->type == EXPRESSION)
				return ft_new_tree_node(ft_duplicate_token(token));
			token_node = token_node->next;
		}
	}
	if (! tree_root)
		return (NULL);
	if (tokens != token_node)
		tree_root->left = ft_parser(tokens);
	if (next_token_node)
		tree_root->right = ft_parser(next_token_node);
	ft_lstclear(&tokens, &free);
	return (tree_root);
}
