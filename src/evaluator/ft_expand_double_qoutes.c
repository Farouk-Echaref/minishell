/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_double_qoutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:27:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:34:00 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

static char	*ft_get_var_ptr(char *value)
{
	while (value && *value)
	{
		if (*value == '$' && ft_is_var(value) > 1)
			return (value);
		value++;
	}
	return (NULL);
}

char	*ft_concat_parts(char **parts)
{
	char	*res;
	char	*temp;
	int		i;

	res = ft_strdup("");
	if (! parts)
		return (res);
	i = 0;
	while (parts[i])
	{
		temp = res;
		res = ft_strjoin(res, parts[i]);
		free(temp);
		i++;
	}
	return (res);
}

static void	ft_free_parts(char **parts)
{
	int	i;

	if (! parts)
		return ;
	i = 0;
	while (parts[i])
	{
		parts[i] = ft_free(parts[i]);
		i++;
	}
}

void	ft_expand_double_qoutes(t_token *token)
{
	char	*parts[4];
	char	*dollar_ptr;
	int		var_length;
	char	*var_name;

	if (! token)
		return ;
	parts[3] = NULL;
	dollar_ptr = ft_get_var_ptr(token->value);
	var_length = ft_is_var(dollar_ptr);
	if (! dollar_ptr || var_length < 2)
		return ;
	var_name = ft_str(dollar_ptr + 1, var_length - 1);
	parts[0] = ft_str(token->value, dollar_ptr - (char *)token->value);
	parts[1] = ft_evaluate_var(var_name);
	parts[2] = ft_strdup(dollar_ptr + var_length);
	token->value = ft_free(token->value);
	token->value = ft_concat_parts(parts);
	token->length = ft_strlen(token->value);
	ft_free_parts(parts);
	var_name = ft_free(var_name);
	ft_expand_double_qoutes(token);
}
