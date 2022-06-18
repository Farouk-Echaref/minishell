/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:58:29 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 21:45:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*t_dest;
	char	*t_src;

	t_dest = dest;
	t_src = (char *)src;
	if (!dest && !src)
		return (0);
	if (t_dest < t_src)
		while (n--)
			*t_dest++ = *t_src++;
	else
	{
		t_dest += n;
		t_src += n;
		while (n--)
			*--t_dest = *--t_src;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	char a[16] = "test";
// 	char b[16] = "test";

// 	ft_memmove(&a[1], &a[0], 3); // Not valid since it overlaps.
// 	memmove(&b[1], &b[0], 3);	 // valid.
// 	printf("a: |%s|, b: |%s|\n", a, b);
// }
