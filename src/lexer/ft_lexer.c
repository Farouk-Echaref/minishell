/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:49:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:59:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "_lexer.h"
#include "list/list.h"
#include "token/token.h"
#include <stdlib.h>

t_lexer	*ft_init_lexer(const char *s)
{
	t_lexer	*lxr;

	lxr = (t_lexer *)malloc(sizeof(t_lexer));
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
				ft_new_token(value, type, len)
				));
	}
	return (tokens);
}
