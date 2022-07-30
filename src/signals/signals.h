/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:52:26 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/28 15:22:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

#include "termios.h"
#include "data/data.h"

void	setup_term(void);
void	ft_ctrl_d();
void	ft_ctrl_c(int sig);
void	ft_handle_signals();
void	ft_setup_term(void);
void	ft_set_signals_default();

#endif
