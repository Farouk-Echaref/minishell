/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_start_with.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:48:28 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 13:51:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

int	ft_str_start_with(char *str, char *start_with)
{
	if (! str || ! start_with)
		return (0);
	if (ft_strlen(str) < ft_strlen(start_with))
		return (0);
	while (start_with)
	{
		if (*str != *start_with)
			return (0);
		start_with++;
		str++;
	}
	return (1);
}
