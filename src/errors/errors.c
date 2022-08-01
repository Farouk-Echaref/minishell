/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:17:39 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:29:09 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	ft_error_message(char *key, char *error_message)
{
	ft_putstr_fd("minishell: ", 2);
	if (key)
	{
		ft_putstr_fd(key, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error_message)
		ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error(char *key)
{
	ft_putstr_fd("minishell: ", 2);
	if (key)
	{
		ft_putstr_fd(key, 2);
		ft_putstr_fd(": ", 2);
	}
}
