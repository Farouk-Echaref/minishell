/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:55:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 22:54:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_get_var_name(char *arg, int *concat)
{
	char	*var_name;

	if (concat)
		*concat = 0;
	if (ft_strchr(arg, '='))
		var_name = ft_str(arg, ft_strchr(arg, '=') - arg);
	else
		var_name = ft_strdup(arg);
	if (var_name[ft_strlen(var_name) - 1] == '+')
	{
		if (concat)
			*concat = 1;
		var_name[ft_strlen(var_name) - 1] = 0;
	}
	return (var_name);
}
