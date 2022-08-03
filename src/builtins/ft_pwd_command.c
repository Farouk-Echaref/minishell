/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:18:25 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 21:39:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_pwd_command(char **command)
{
	static char	cwd[256];

	(void)command;
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
