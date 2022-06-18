/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:03:03 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/07 11:24:20 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_should_stop(
	int n, unsigned const char *s1, unsigned const char *s2
) {
	if (n < 0)
		return (!(*s1 && *s2 && *s1 == *s2));
	return (!(n > 1 && *s1 && *s2 && *s1 == *s2));
}

int	ft_strncmp(const char *t1, const char *t2, size_t n)
{
	unsigned char const	*s1;
	unsigned char const	*s2;

	s1 = (unsigned char const *)t1;
	s2 = (unsigned char const *)t2;
	if (n <= 0)
		return (0);
	while (!ft_should_stop(n--, s1, s2))
	{
		s1++;
		s2++;
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}
