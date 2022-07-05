/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 09:27:01 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

char	*ft_evaluate_var(char *var , char **env)
{
	int		i;
	char	*res;
	char	**store;

	i = 0;
	res = NULL;
	store = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
		{
			store = ft_split(env[i], '=');
			res = store[1];
			store[0] = ft_free(store[0]);
			return (res);
		}
		i++;
	}
	return (NULL);
}


void	ft_expand_expression_list(t_list *tokens, char **argenv)
{
	while (tokens)
	{
		ft_expand_expression(ft_get_token(tokens), argenv);
		tokens = tokens->next;
	}
}

void	ft_merge_tokens(t_token *token)
{
	char	*result;
	t_list	*tokens;
	char	*temp;
	char	*str;

	result = ft_strdup("");
	tokens = token->value;
	while (tokens)
	{
		if (ft_get_token(tokens)->value)
		{
			temp = result;
			str = ft_str(ft_get_token(tokens)->value, ft_get_token(tokens)->length);
			result = ft_strjoin(result, str);
			str = ft_free(str);
			temp = ft_free(temp);
		}
		tokens = tokens->next;
	}
	token->type = EXPRESSION;
	ft_lstclear((t_list **)&token->value, free);
	token->value = result;
	token->is_list = 0;
}

void	ft_expand_expression(t_token *token, char **argenv)
{
	 int		i;
	 int		j;
	// char	*tmp;
	// char	*store;
	// char	*res;

	i = 0;
	j = 0;
	if (token->is_list) {
		ft_expand_expression_list(token->value, argenv);
		ft_merge_tokens(token);
	} else if (token->type == SING_QUOT) {
		token->value++;
		token->length -= 2;
	} else if (token->type == DOUB_QUOT) {
		// evaluate variables
		token->value++;
		token->length -= 2;
		token->value = ft_str(token->value, token->length);
		// store = ft_strchr(token->value, "$");
		// if (store != NULL)
		// {
		// 	tmp = ft_evaluate_var(store+1, argenv);
		// 	token->length+=len;
		// 	res = (char *)malloc(sizeof(char) * token->length + 100);
		// 	while (token->value)
		// 	{
		// 		if (token->value[i] == '$')
		// 		{
		// 			res[i] = tmp[j];
		// 			i++;
		// 			j++;
		// 		}
		// 		res[i] = token->value[i];
		// 		i++;

		// 	}
		// }
	} else if (token->type == VAR) {
		token->value++;
		token->length--;
		char *str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str, argenv);
		token->length = ft_strlen(token->value);
		str = ft_free(str);
	}
}
