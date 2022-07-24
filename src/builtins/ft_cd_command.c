/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:10:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 21:41:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_set_env(char *var_name, char *value)
{
	t_list	*target_node;

	target_node = ft_search_env(var_name);
	if (! target_node)
		return ;
	target_node->content = ft_free(target_node->content);
	target_node->content = ft_make_env_line(var_name, value);
}

void	ft_cd_command(char **command)
{
	char	*path;
	char	wd[256];

	path = command[1];
	if (! path || ft_strcmp(path, "~") == 0)
		path = ft_evaluate_var("HOME");
	if (ft_strcmp(path, "-") == 0)
		path = ft_evaluate_var("OLDPWD");
	if (getcwd(wd, sizeof(wd)) == NULL)
		return (perror("getcwd() error"));
	ft_set_env("OLDPWD", wd);
	if (chdir(path) != 0)
		return (perror("minishell: cd"));
	if (getcwd(wd, sizeof(wd)) == NULL)
		return (perror("getcwd() error"));
	ft_set_env("PWD", wd);
}
