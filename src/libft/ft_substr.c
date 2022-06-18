/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:43:52 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/07 12:43:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*sub_str;
	unsigned int	i;
	unsigned int	substr_len;

	if (!s)
		return (0);
	str = (char *)s;
	substr_len = ft_strlen(str);
	if (len < ft_strlen(str))
		substr_len = len;
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	sub_str = (char *)malloc(substr_len + 1);
	if (!sub_str)
		return (0);
	str += start;
	i = 0;
	while (str && *str && substr_len--)
		sub_str[i++] = *str++;
	sub_str[i] = '\0';
	return (sub_str);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
	// char *s = ft_substr("tripouille", 0, 2);
	// printf("%s\n", s);
	// if (!strcmp(s, ""))
	// 	printf("success");
	// else
	// 	printf("fail");
	// free(s);
// }
