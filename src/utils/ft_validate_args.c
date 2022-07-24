/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:05:27 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 14:06:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

static int	ft_is_int(char *str)
{
	char	*result;

	result = ft_itoa(ft_atoi(str));
	if (ft_strlen(result) != ft_strlen(str))
		return (0);
	if (ft_strncmp(str, result, ft_strlen(str)) != 0)
		return (0);
	free(result);
	return (1);
}

int	ft_isvalidnumber(char *s)
{
	char	*str;
	char	*str_backup;

	if (! s || *s == '\0')
		return (0);
	str = ft_strtrim(s, " ");
	str_backup = str;
	if (*str == '+' || *str == '-')
		str++;
	while (str && *str == '0')
	{
		str++;
		if (! *str)
			return (1);
	}
	if (! ft_is_int(str))
		return (free(str_backup), 0);
	free(str_backup);
	return (1);
}
