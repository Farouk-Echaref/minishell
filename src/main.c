/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/22 04:16:53 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "token/token.h"
#include "lexer/lexer.h"
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>


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
	char	*s = "ls -al|grep 2>";
	t_lexer	*lxr;
	while (1)
	{
		s = readline("minishell> ");
		lxr = ft_init_lexer(s);
		ft_lexer(lxr);
		printf("%p\n", lxr->tokens);
		t_list	*lst = lxr->tokens;
		t_token *token = NULL;
		while (lst)
		{
			token = lst->content;
			printf("%d					%s						=> %d\n", token->type, ft_str(token->value, token->length), token->length);
			lst = lst->next;
		}
		ft_destroy_lexer(lxr);
	}
}
