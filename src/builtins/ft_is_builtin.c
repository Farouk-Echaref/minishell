/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:57:45 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 22:02:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_is_builtin(char *command_name)
{
	int			i;
	static char	*builtin_commands[] = {
		"env",
		"exit",
		"echo",
		"unset",
		"export",
		"pwd",
		"cd",
		0
	};

	i = 0;
	while (builtin_commands[i])
	{
		if (ft_strcmp(builtin_commands[i], command_name) == 0)
			return (1);
		i++;
	}
	return (0);
}
