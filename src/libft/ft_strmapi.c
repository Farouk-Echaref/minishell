/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:11:51 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/06 14:32:31 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (s && s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// char	t(unsigned int index, char c)
// {
// 	index = 0;
// 	return (c + 1);
// }

// int main()
// {
// 	char s[] = "Mohamed";
// 	ft_putstr_fd(ft_strmapi(s, t), 1);
// 	ft_putchar_fd('\n', 1);
// }
