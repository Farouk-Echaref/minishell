/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_double_qoutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:27:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 14:14:35 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_double_qoutes(t_token *token, char **env)
{
    char    *part1;
    char    *part2;
    char    *part3;
    char    *token_value;
	char	*str;

    if (! token)
        return ;
    char	*dollar = ft_strchr(token->value, '$');
    int		dollar_len = ft_is_var(dollar);
    if (dollar && dollar_len > 1)
    {
        token_value = token->value;
        part1 = ft_str(token->value, dollar - token_value);
		str = ft_str(dollar, dollar_len);
        part2 = ft_evaluate_var(str + 1, env);
		str = ft_free(str);
        part3 = ft_strdup(dollar + dollar_len);
		token_value = ft_free(token_value);
		token_value = ft_strjoin(part1, part2);
        token->value = ft_strjoin(token_value, part3);
		token->length = ft_strlen(token->value);
		token_value = ft_free(token_value);
		part1 = ft_free(part1);
		part2 = ft_free(part2);
		part3 = ft_free(part3);
        ft_expand_double_qoutes(token, env);
    }
}
