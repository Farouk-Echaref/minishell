/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:49:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 01:30:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "_lexer.h"
#include "list/list.h"
#include "token/token.h"
#include <stdlib.h>
#include "utils/utils.h"

t_lexer	*ft_init_lexer(const char *s)
{
	t_lexer	*lxr;

	lxr = (t_lexer *)malloc(sizeof(t_lexer));
	if (! lxr)
		exit(1);
	lxr->start = s;
	lxr->content = s;
	return (lxr);
}

void	ft_destroy_lexer(t_lexer *lxr)
{
	if (! lxr)
		return ;
	free(lxr);
}

static t_token	*ft_make_token(char *value, t_type token_type, int len)
{
	t_token	*t;

	if (
		token_type == SING_QUOT
		|| token_type == DOUB_QUOT
		|| token_type == SUB_CMD
	)
	{
		len -= 2;
		value++;
	}
	if (len < 0)
	{
		t = ft_new_token(ft_str(value, 0), token_type);
		t->is_valid = 0;
	}
	else
		t = ft_new_token(ft_str(value, len), token_type);
	return (t);
}

t_list	*ft_lexer(t_lexer *lxr)
{
	t_type	type;
	void	*value;
	int		len;
	t_list	*tokens;

	tokens = NULL;
	while (lxr->content && *lxr->content)
	{
		value = (void *)lxr->content;
		type = ft_get_type(lxr);
		len = lxr->content - (char *)value;
		ft_lstadd_back(&tokens, ft_lstnew(
				ft_make_token(value, type, len)
				));
	}
	return (tokens);
}
