/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:16:40 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 02:41:06 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_exit_command(char **command)
{
	char			*arg;
	unsigned char	exit_status;

	arg = command[1];
	write (1, "exit\n", 5);
	if (ft_arr_size(command) > 2)
	{
		g_.exit_status = 1;
		ft_error_message("exit", "too many arguments");
		return ;
	}
	if (! arg)
		exit(g_.exit_status);
	if (ft_isvalidnumber(arg)) {
		exit_status = ft_atoi(arg);
		exit(exit_status);
	} else {
		ft_error_message("exit", "numeric argument required");
		exit(-1);
	}
}
