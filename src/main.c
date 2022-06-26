/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/26 07:35:11 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data/data.h"
#include "token/token.h"
#include "lexer/lexer.h"
#include "list/list.h"
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

void	print_token(void *_token)
{
	t_token	*token = (t_token *)_token;
	printf(
		"%d					%s						=> %d\n",
		token->type,
		ft_str(token->value, token->length),
		token->length
	);
}

int main()
{
	t_data	data;
	char	*s = "ls -al|grep 2>";
	t_lexer	*lxr;

	ft_init_data(&data);
	while (1)
	{
		s = readline("minishell> ");
		lxr = ft_init_lexer(s);
		data.tokens = ft_lexer(lxr);
		// data.tree = ft_parser(data.tokens);
		ft_lstiter(data.tokens, print_token);
		ft_destroy_lexer(lxr);
		ft_destroy_data(&data);
	}
}
