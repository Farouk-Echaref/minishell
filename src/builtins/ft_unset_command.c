/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:24:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 01:59:36 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_is_target(char *var_name, char *env_line)
{
	int	len_var_name;

	len_var_name = (int)ft_strlen(var_name);
	if (
		ft_strncmp(var_name, env_line, ft_strlen(var_name)) == 0
		&& len_var_name == ft_strchr(env_line, '=') - (char *)env_line
	)
		return (1);
	return (0);
}

static void	ft_unset(char *var_name)
{
	t_list	*env;

	env = g_.env;
	if (! var_name)
		return ;
	if (ft_is_target(var_name, env->content))
		g_.env = env->next;
	while (env)
	{
		if (ft_is_target(var_name, env->content))
		{
			env = ft_lstdetach(env);
			env->content = ft_free(env->content);
			env = ft_free(env);
			break ;
		}
		env = env->next;
	}
}

void	ft_unset_command(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (! ft_check_var_syntax(argv[i]))
		{
			ft_error_message(argv[i], "not a valid identifier");
			g_.exit_status = 1;
		}
		else
			ft_unset(argv[i]);
		i++;
	}
}
