/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:53:26 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/22 20:10:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"
#include <signal.h>
#include <unistd.h>

static void	ft_nothing(int sig)
{
	sig = 0;
}

static void ft_ctrl_c(int sig)
{
	sig = 0;
}

void	ft_handle_signals()
{
	signal(SIGQUIT, ft_nothing);
	signal(SIGINT, ft_ctrl_c);
}
