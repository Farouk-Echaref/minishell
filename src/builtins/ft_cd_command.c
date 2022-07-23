/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:10:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 21:38:29 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_cd_command(char **command)
{
	char	*path;

	path = command[1];
	if (! path)
		return ;
	if (chdir(path) != 0)
		perror("minishell: cd");
}
