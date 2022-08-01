/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:42 by fech-cha          #+#    #+#             */
/*   Updated: 2022/08/01 22:26:49 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdlib.h>
# include "list/list.h"
# include "tree/tree.h"

typedef enum e_type		t_type;
typedef struct s_token	t_token;

enum e_type
{
	WHITE_SPACE = 4,
	REDIR_RIGHT = 5,
	REDIR_LEFT = 6,
	SHIFT_LEFT = 7,
	SHIFT_RIGHT = 8,
	AND_OPR = 9,
	OR_OPR = 10,
	STAR = 11,
	SUB_CMD = 12,
	SING_QUOT = 13,
	DOUB_QUOT = 14,
	PIPE = 15,
	VAR = 16,
	EXPRESSION = 18,
	OTHER = 19,
	SPLITED_VAR = 20
};

struct s_token
{
	t_type	type;
	void	*value;
	int		length;
	int		is_list;
	int		is_filename;
	int		is_herdoc_expr_list;
};

t_token	*ft_new_token(void *value, t_type type, int length);
t_token	*ft_duplicate_token(const t_token *t);
t_list	*ft_duplicate_tokens_list(const t_list	*tokens);
t_type	ft_get_token_type(t_list	*lst);
t_token	*ft_get_token(t_list *lst);
int		ft_is_redirection(t_type token_type);
void	ft_free_token(void *tree_content);
void	ft_free_token_no_value(void *tree_content);
t_token	*ft_get_token_tree(t_tree *tree);
int		ft_contains_token(t_list *lst, t_type token_type);
t_list	*ft_lstflatten_tokens(t_list *tokens);
int		ft_is_herdoc_tree(t_tree *tree);

#endif
