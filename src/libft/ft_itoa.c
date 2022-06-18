/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:47:36 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/08 21:25:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int	ft_getnbr_length(int nbr)
{
	int	count;

	count = 1;
	while (nbr / 10)
	{
		count++;
		nbr /= 10;
	}
	if (nbr < 0)
		return (count + 1);
	return (count);
}

static char	*ft_handle_min_zero(int nb)
{
	if (nb == INT_MIN)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("0"));
}

char	*ft_itoa(int nb)
{
	char	*res;
	int		i;
	int		nb_len;

	if (nb == INT_MIN || nb == 0)
		return (ft_handle_min_zero(nb));
	nb_len = ft_getnbr_length(nb);
	res = (char *)ft_calloc(nb_len + 1, 1);
	if (!res)
		return (0);
	i = nb_len - 1;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (i > 0)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (nb > 0)
		res[i] = nb % 10 + '0';
	res[nb_len] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <string.h>
// #include <limits.h>

// int main()
// {
// 	printf("%s\n", ft_itoa(100));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-100));
// 	printf("%s\n", ft_itoa(INT_MAX));
// 	printf("%s\n", ft_itoa(INT_MIN));
// 	printf("%d\n", ft_getnbr_length(-234));
// }
