/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:36:11 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/07 13:07:29 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_start(char const *s1, char const *set)
{
	int	pos;

	pos = 0;
	while (s1 && s1[pos])
	{
		if (!ft_strchr(set, s1[pos]))
			return (pos);
		pos++;
	}
	return (pos);
}

static int	ft_get_end(char const *s1, char const *set)
{
	int	pos;

	pos = ft_strlen(s1) - 1;
	while (s1 && s1[pos] && pos > 0)
	{
		if (!ft_strchr(set, s1[pos]))
			return (pos);
		pos--;
	}
	return (pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1)
		return (0);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start > end)
		return ((char *)ft_calloc(1, 1));
	return (ft_substr(s1, start, end - start + 1));
}

// #include <stdio.h>
// int main()
// {
// 	char *res = ft_strtrim("   xxxtripouille", " x");
// 	printf("%s\n", res);
// 	char *s = ft_strtrim("abcdba", "acb");
// 	printf("%s\n", ft_substr("mohamed", 3, 2));
// 	printf("%s\n", s);
// }
