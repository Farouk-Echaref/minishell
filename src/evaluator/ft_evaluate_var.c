/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:59 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:31:16 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

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
	return (ft_strdup(""));
}
