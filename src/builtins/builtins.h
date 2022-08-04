/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:56:35 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 01:49:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft/libft.h"
# include "str_utils/str_utils.h"
# include <unistd.h>
# include <stdio.h>
# include "list/list.h"
# include "data/data.h"
# include "evaluator/evaluator.h"
# include "env/env.h"

typedef void	(*t_command_func)(char **);

int				ft_is_builtin(char *command_name);
t_command_func	ft_select_builtin_command(char *command_name);
void			ft_echo_command(char **cmd);
void			ft_exit_command(char **command);
void			ft_cd_command(char **command);
void			ft_pwd_command(char **command);
void			ft_env_command(char **command);
void			ft_unset_command(char **command);
int				ft_should_run_on_main_process(char *command_name);
void			ft_export_command(char **argv);
int				ft_check_var_syntax(char *var_name);

#endif
