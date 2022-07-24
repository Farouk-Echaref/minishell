/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:38:09 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 13:31:29 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_env_command(char **command)
{
	t_list	*env;

	(void)command;
	env = g_.env;
	while (env)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
}
