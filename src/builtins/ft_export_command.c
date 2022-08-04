/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:19:25 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 02:56:00 by mzarhou          ###   ########.fr       */
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

static int	ft_export(char *arg)
{
	char	*var_name;
	char	*value;
	int		concat;

	var_name = ft_get_var_name(arg, &concat);
	value = ft_var_value(arg);
	if (ft_check_var_syntax(var_name) == 0)
		return (ft_free(var_name), ft_free(value), 0);
	ft_add_env(var_name, value, concat);
	value = ft_free(value);
	var_name = ft_free(var_name);
	return (1);
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
