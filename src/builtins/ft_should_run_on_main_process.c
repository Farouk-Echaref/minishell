/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_should_run_on_main_process.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:48:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 02:48:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_should_run_on_main_process(char *command_name)
{
	if (
		ft_strcmp(command_name, "exit") == 0
		|| ft_str_start_with(command_name, "exit ")
		|| ft_strcmp(command_name, "unset") == 0
		|| ft_str_start_with(command_name, "unset ")
		|| ft_strcmp(command_name, "export") == 0
		|| ft_str_start_with(command_name, "export ")
		|| ft_strcmp(command_name, "cd") == 0
		|| ft_str_start_with(command_name, "cd ")
		|| ft_strcmp(command_name, "pwd") == 0
		|| ft_str_start_with(command_name, "pwd ")
	)
		return (1);
	return (0);
}
