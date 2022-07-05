/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 06:21:31 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>

char	*ft_evaluate_var(char *var , char **env)
{
	int		i;
	int		j;
	int		index;
	char	*res;

	i = 0;
	index = 0;
	res = malloc(sizeof(char) * 500);
	if (res == NULL)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (var[j])
			j++;
		if (ft_strncmp(env[i], var, j) == 0)
		{
			// store = ft_split(env[i], '=');
			// res = store[1];
			while (env[i][j])
			{
				res[index] = env[i][++j];
				index++;
			}
			free (var);
			return (res);
		}
		i++;
	}
	free (var);
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
	if (token->is_list) {
		ft_expand_expression_list(token->value, argenv);
		ft_merge_tokens(token);
	} else if (token->type == SING_QUOT) {
		token->value++;
		token->length -= 2;
		token->value = ft_str(token->value, token->length);
	} else if (token->type == DOUB_QUOT) {
		// evaluate variables
		token->value++;
		token->length -= 2;
		token->value = ft_str(token->value, token->length);
	} else if (token->type == VAR) {
		// evaluate variables
		token->value++;
		token->length--;
		char *str = ft_str(token->value, token->length);
		token->value = ft_evaluate_var(str, argenv);
		token->length = ft_strlen(str);
	}
}
