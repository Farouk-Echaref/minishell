/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:06:30 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 07:06:40 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

char	**ft_arr_shift(char **command, char *str)
{
	char	**new_arr;
	int		new_size;
	int		i;

	new_size = ft_arr_size(command) + 2;
	new_arr = (char **)malloc(sizeof(char *) * new_size);
	i = 0;
	new_arr[0] = str;
	while (command[i])
	{
		new_arr[i + 1] = command[i];
		i++;
	}
	command = ft_free(command);
	new_arr[i + 2] = NULL;
	return (new_arr);
}
