/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_double_qoutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:27:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:52:17 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_expand_double_qoutes(t_token *token, char **env)
{
    char    *part1;
    char    *part2;
    char    *part3;
    char    *token_value;

    if (! token)
        return ;
    char	*dollar = ft_strchr(token->value, '$');
    int		dollar_len = ft_is_var(dollar);
    if (dollar && dollar_len > 1)
    {
        token_value = token->value;
        part1 = ft_str(token->value, dollar - token_value);
        part2 = ft_evaluate_var(ft_str(dollar, dollar_len) + 1, env);
        part3 = ft_strdup(dollar + dollar_len);
        token->value = ft_strjoin(ft_strjoin(part1, part2), part3);
		token->length = ft_strlen(token->value);
        ft_expand_double_qoutes(token, env);
    }
}
