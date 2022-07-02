/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:04:27 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 07:05:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

void	ft_reverse_arr(char **arr)
{
	int		i;
	int		j;
	char	*str;

	if (! arr)
		return ;
	j = ft_arr_size(arr) - 1;
	i = 0;
	while (i < j)
	{
		str = arr[i];
		arr[i] = arr[j];
		arr[j] = str;
		i++;
		j--;
	}
}
