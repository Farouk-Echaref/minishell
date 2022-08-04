/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:49:16 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/04 01:49:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
