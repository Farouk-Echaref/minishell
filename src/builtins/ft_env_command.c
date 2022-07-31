/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:38:09 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 05:51:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_env_command(char **command)
{
	t_list	*env;

	env = g_.env;
	if (ft_arr_size(command) > 1)
	{
		ft_error_message("env", "too many arguments");
		exit(EXIT_FAILURE);
	}
	while (env)
	{
		if (ft_strchr(env->content, '='))
			printf("%s\n", (char *)env->content);
		env = env->next;
	}
	exit(EXIT_SUCCESS);
}
