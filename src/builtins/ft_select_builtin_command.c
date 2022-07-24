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
	exit(EXIT_SUCCESS);
}

t_command_func ft_select_builtin_command(char *command_name)
{

	if (ft_strcmp(command_name, "echo") == 0 || ft_strcmp(command_name, "ECHO") == 0)
		return (ft_echo_command);
	if (ft_strcmp(command_name, "exit") == 0)
		return (ft_exit_command);
	if (ft_strcmp(command_name, "cd") == 0)
		return (ft_cd_command);
	if (ft_strcmp(command_name, "pwd") == 0)
		return (ft_pwd_command);
	if (ft_strcmp(command_name, "env") == 0 || ft_strcmp(command_name, "ENV") == 0)
		return (ft_env_command);
	if (ft_strcmp(command_name, "unset") == 0)
		return (ft_unset_command);
	return (f);
}
