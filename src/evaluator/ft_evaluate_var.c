/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:59 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 15:13:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

char	*ft_evaluate_var(char *var , char **env)
{
	int		i;
	char	**store;

	i = 0;
	store = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
			return ft_strdup(ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (ft_strdup(""));
}
