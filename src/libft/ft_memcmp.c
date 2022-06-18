/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:33:22 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/07 15:58:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *t1, const void *t2, size_t n)
{
	unsigned char const	*s1;
	unsigned char const	*s2;

	s1 = (unsigned char const *)t1;
	s2 = (unsigned char const *)t2;
	if (n <= 0)
		return (0);
	while (n-- > 1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s1 = "testtest";
// 	char *s2 = "te2ttest";
// 	printf("%d\n", memcmp(s1, s2, 5));
// }
