/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:59 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 06:35:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

char	*ft_evaluate_var(char *var)
{
	t_list	*env;

	env = g_.env;
	if (ft_strcmp(var, "?") == 0)
		return (ft_itoa(g_.exit_status));
	while (env)
	{
		if (
			(int) ft_strlen(var) == (ft_strchr(env->content, '=') - (char *)env->content)
			&& ft_strncmp(env->content, var, ft_strchr(env->content, '=') - (char *)env->content) == 0
			&& ft_strchr(env->content, '=')
		)
			return ft_strdup(ft_strchr(env->content, '=') + 1);
		env = env->next;
	}
	return (ft_strdup(""));
}
