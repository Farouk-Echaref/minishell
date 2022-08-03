/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:56:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 22:54:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_var_value(char *line)
{
	char	*value;

	value = NULL;
	if (line && ft_strchr(line, '='))
		value = ft_strdup(ft_strchr(line, '=') + 1);
	return (value);
}
