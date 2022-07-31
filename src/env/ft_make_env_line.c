/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_env_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:29:19 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 06:18:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env/env.h"

char	*ft_make_env_line(char *var_name, char *value)
{
	char	*result;
	char	*temp;

	if (! var_name)
		return (NULL);
	if (! value)
		result = ft_strdup(var_name);
	else {
		temp = ft_strjoin(var_name, "=");
		result = ft_strjoin(temp, value);
		temp = ft_free(temp);
	}
	return (result);
}
