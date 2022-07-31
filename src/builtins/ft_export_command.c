/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:19:25 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:53:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_sort_print(void)
{
	char	**arr;
	int		i;

	arr = ft_lst2arr(g_.env);
	ft_sort(arr, ft_arr_size(arr));
	i = 0;
	while (arr[i])
	{
		printf("declare -x  %s\n", (char *)arr[i]);
		i++;
	}
	arr = ft_arr_free(arr);
}

int	ft_check_var_syntax(char *var_name)
{
	if (! var_name || (! ft_isalpha(*var_name) && *var_name != '_'))
		return (0);
	while (var_name && *var_name)
	{
		if (! ft_isalnum(*var_name) && *var_name != '_')
			return (0);
		var_name++;
	}
	return (1);
}

static void	ft_add_env(char *var_name, char *value, int concat)
{
	char	*line;
	t_list	*old_line;
	char	*old_value;

	if (! var_name)
		return ;
	old_value = NULL;
	old_line = ft_search_env(var_name);
	if (old_line && ft_strchr(old_line->content, '='))
		old_value = ft_strdup(ft_strchr(old_line->content, '=') + 1);
	if (! value && old_value)
		return (free(old_value));
	if (old_line)
	{
		old_line->content = ft_free(old_line->content);
		ft_free(ft_lstdetach(old_line));
	}
	if (concat && old_value)
		value = ft_assign_free(&value, ft_strjoin(old_value, value));
	line = ft_make_env_line(var_name, value);
	ft_lstadd_back(&g_.env, ft_lstnew(line));
	old_value = ft_free(old_value);
}

static int	ft_export(char *arg)
{
	char	*var_name;
	char	*value;
	int		concat;

	concat = 0;
	value = NULL;
	if (ft_strchr(arg, '='))
		var_name = ft_str(arg, ft_strchr(arg, '=') - arg);
	else
	{
		var_name = ft_strdup(arg);
		if (var_name[ft_strlen(var_name) - 1] == '+')
			return (free(var_name), 0);
	}
	if (var_name[ft_strlen(var_name) - 1] == '+')
	{
		concat = 1;
		var_name[ft_strlen(var_name) - 1] = 0;
	}
	if (ft_check_var_syntax(var_name) == 0)
		return (ft_free(var_name), 0);
	if (ft_strchr(arg, '='))
		value = ft_strdup(ft_strchr(arg, '=') + 1);
	ft_add_env(var_name, value, concat);
	return (ft_free(value), ft_free(var_name), 1);
}

void	ft_export_command(char **argv)
{
	int		i;

	if (! argv[1])
		return (ft_sort_print());
	i = 1;
	while (argv[i])
	{
		if (! ft_export(argv[i]))
		{
			ft_error_message(argv[i], "not a valid identifier");
			g_.exit_status = 1;
		}
		i++;
	}
}
