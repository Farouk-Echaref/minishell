/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:43:07 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:14:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_str(const char *s, int len)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i] != '\0' && i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
