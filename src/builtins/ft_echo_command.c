/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:15:25 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/31 21:32:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_print_args(char **args, int index)
{
	while (args[index])
	{
		printf("%s", args[index]);
		index++;
		if (args[index])
			printf (" ");
	}
}

int	ft_check_nl(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
	{
		str++;
		while (str && *str)
		{
			if (*str != 'n')
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

void	ft_echo_command(char **cmd)
{
	int	i;
	int	nl;

	i = 1;
	nl = 0;
	if (!cmd)
		return (exit(EXIT_SUCCESS));
	while (*cmd && ft_check_nl(cmd[i]))
	{
		nl = 1;
		i++;
	}
	ft_print_args(cmd, i);
	if (!nl)
		printf ("\n");
	exit(EXIT_SUCCESS);
}
