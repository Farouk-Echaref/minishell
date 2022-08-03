/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:22:47 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:04:30 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

static char	*ft_char_helper(char c)
{
	char	*result;

	result = (char *)malloc(2);
	if (! result)
		exit(1);
	result[0] = c;
	result[1] = 0;
	return (result);
}

static void	ft_add_chars(t_list **lst_ptr, char *s)
{
	t_token	*token;

	while (s && *s)
	{
		token = ft_new_token(ft_char_helper(*s), EXPRESSION);
		ft_lstadd_back(lst_ptr, ft_lstnew(token));
		s++;
	}
}

t_list	*ft_split_pattern(t_list *lst)
{
	t_list	*result;
	t_token	*token;

	result = NULL;
	while (lst)
	{
		if (ft_get_token(lst)->type == STAR)
		{
			token = ft_duplicate_token(lst->content);
			token->value = ft_strdup(token->value);
			ft_lstadd_back(&result, ft_lstnew(token));
		}
		else
			ft_add_chars(&result, ft_get_token(lst)->value);
		lst = lst->next;
	}
	return (result);
}
