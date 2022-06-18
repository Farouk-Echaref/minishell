/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcp7 <thcp7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:03:46 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/04 12:28:39 by thcp7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	s += len;
	while (len--)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "mohamed";
// 	printf("%s", ft_strrchr(s, 'm'));
// }
