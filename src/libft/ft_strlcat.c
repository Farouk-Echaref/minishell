/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:01:24 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 17:03:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	n;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	n = dest_len;
	if (size <= dest_len)
		return (src_len + size);
	while (src && *src && n < size - 1)
		dest[n++] = *src++;
	if (dest)
		dest[n] = '\0';
	return (src_len + dest_len);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char s[] = "pouic ";
// 	char d[100] = "pouic";
// 	char d2[100] = "pouic";
// 	printf("%lu\n", strlcat(d, s, 7));
// 	printf("%d\n", ft_strlcat(d2, s, 7));
// 	printf("%s\n", d);
// 	printf("%s\n", d2);
// }
