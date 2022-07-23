/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:59 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 01:16:54 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

char	*ft_evaluate_var(char *var , char **env)
{
	int		i;

	i = 0;
	if (ft_strcmp(var, "?") == 0)
		return (ft_itoa(g_.exit_status));
	while (env[i])
	{
		if (
			(int) ft_strlen(var) == (ft_strchr(env[i], '=') - env[i])
			&& ft_strncmp(env[i], var, ft_strchr(env[i], '=') - env[i]) == 0
		)
			return ft_strdup(ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (ft_strdup(""));
}
