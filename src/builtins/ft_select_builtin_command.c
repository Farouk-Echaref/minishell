/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_builtin_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:14:52 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 17:58:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static	void f(char **command)
{
	(void)command;
}

t_command_func ft_select_builtin_command(char *command_name)
{
	if (ft_strcmp(command_name, "exit") == 0)
		return (ft_exit_command);
	return (f);
}
