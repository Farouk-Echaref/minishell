/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:07:50 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 21:50:59 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	int size = 4;
// 	int	*arr = (int*)ft_calloc(size, sizeof(int));
// 	while (size--)
// 	{
// 		printf("%d\n", arr[size]);
// 	}
// 	printf("-----------------------\n");
// 	size = 4;
// 	while (size--)
// 	{
// 		arr[size] = 9;
// 	}
// 	size = 4;
// 	while (size--)
// 	{
// 		printf("%d\n", arr[size]);
// 	}
// }
