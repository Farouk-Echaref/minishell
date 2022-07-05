/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:21:37 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 11:48:25 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	*ft_strcut(char *start, char *end)
{
	char	*res;
	int		i;

	if (! start || ! end || start >= end)
		return ft_strdup("");
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (*start && start < end)
		res[i++] = *start++;
	res[i] = 0;
	return (res);
}
