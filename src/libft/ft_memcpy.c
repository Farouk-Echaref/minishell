/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:57:55 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 21:27:32 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*t_dest;
	char	*t_src;

	t_dest = dest;
	t_src = (char *)src;
	if (!dest && !src)
		return (0);
	while (n--)
		*t_dest++ = *t_src++;
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
//     // char a[16] = "test";
//     // char b[16] = "sd";

//     // ft_memcpy(&a[1], &a[0],10);  // Not valid since it overlaps.
//     // memcpy(&a[0], &a[1],10); // valid.
//     // printf("a: %s, b: %s\n", a, b);
// 	ft_memcpy(((void *)0), ((void *)0), 3);
// }
