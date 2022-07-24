/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:16:40 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 14:08:17 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_exit_command(char **command)
{
	char			*arg;
	unsigned char	exit_status;

	(void)command;
	arg = command[1];
	write (1, "exit\n", 5);
	if (! arg)
		exit(g_.exit_status);
	if (ft_isvalidnumber(arg)) {
		exit_status = ft_atoi(arg);
		exit(exit_status);
	} else {
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg, 2);
		perror(": ");
		exit(-1);
	}
}
