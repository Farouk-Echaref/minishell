/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/26 21:35:02 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_get_type_order(t_token *token)
{
	t_type	type;

	if (! token)
		return (6);
	type = token->type;
	if (type == AND_OPR || type == OR_OPR)
		return (10);
	if (type == PIPE)
		return (9);
	if (ft_is_redirection(type))
		return (8);
	if (token->is_filename)
		return (7);
	return (6);
}

t_tree	*ft_change_root(t_tree *old_root, t_tree *new_root)
{
	if (! new_root)
		return (old_root);
	new_root->left = old_root;
	return (new_root);
}

void	ft_parser_rec(t_tree **root_ptr, t_token *token)
{
	t_token	*root_content;

	if (! root_ptr)
		return ;
	root_content = NULL;
	if (*root_ptr)
		root_content = (*root_ptr)->content;
	if (
		! root_content || (ft_get_type_order(root_content)
			<= ft_get_type_order(token)
		))
		*root_ptr = ft_change_root(
				*root_ptr,
				ft_new_tree_node(ft_duplicate_token(token)));
	else if (ft_is_redirection(root_content->type) && ! token->is_filename)
		ft_parser_rec(&(*root_ptr)->left, token);
	else if (*root_ptr)
		ft_parser_rec(&(*root_ptr)->right, token);
}

void	ft_allocate_tree_nodes(t_tree *root)
{
	t_token	*token;

	if (! root)
		return ;
	token = root->content;
	if (token->is_list)
		ft_lstiter(token->value, (t_lstiter_func)ft_cleanup_token);
	else
		ft_cleanup_token(token);
	ft_allocate_tree_nodes(root->left);
	ft_allocate_tree_nodes(root->right);
}

t_tree	*ft_parser(t_list *tokens)
{
	t_tree	*root;
	t_token	*token;

	root = NULL;
	token = NULL;
	while (tokens)
	{
		token = tokens->content;
		if (token->type != WHITE_SPACE)
			ft_parser_rec(&root, token);
		tokens = tokens->next;
	}
	ft_allocate_tree_nodes(root);
	return (root);
}
