/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/22 00:50:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "token/token.h"
#include "lexer/lexer.h"
#include "libft/libft.h"


char	*ft_str(const char *s, int len)
{
	int	i = 0;
	if (!s)
		return NULL;
	char *res = (char *)malloc(sizeof(char) * len + 1);
	while (s[i] != '\0' && i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int main()
{
	char	*s = "ls -a > test.txt && cat << ts 1> test.txt";
	t_lexer	*lxr = ft_init_lexer(s);
	ft_lexer(lxr);
	printf("%p\n", lxr->tokens);
	t_list	*lst = lxr->tokens;
	t_token *token = NULL;

	while (lst)
	{
		token = lst->content;
		printf("%d					%s						 		=> %d\n", token->type, ft_str(token->value, token->length), token->length);
		lst = lst->next;
	}
	ft_destroy_lexer(lxr);
}
