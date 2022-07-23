/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:56:35 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 19:21:18 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "str_utils/str_utils.h"
# include <unistd.h>
# include <stdio.h>

typedef void (*t_command_func)(char **);

int				ft_is_builtin(char *command_name);
t_command_func	ft_select_builtin_command(char *command_name);
void			ft_exit_command(char **command);
void			ft_cd_command(char **command);
void			ft_pwd_command(char **command);

#endif
