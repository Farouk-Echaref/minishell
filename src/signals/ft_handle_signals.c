/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:53:26 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 01:54:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"
#include <readline/readline.h>
# include <readline/history.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void setup_term(void)
{
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ECHOCTL;
    tcsetattr(0, TCSANOW, &t);
}

void	ft_ctrl_c(int sig)
{
	(void)sig;
	if (g_.running_status != 1)
		return ;
	write (1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_ctrl_d(void)
{
	write (1, "exit\n", 5);
	exit(0);
}

void ft_handle_signals()
{
	setup_term();
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_ctrl_c);
}
