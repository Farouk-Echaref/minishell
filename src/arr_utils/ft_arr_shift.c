/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:06:30 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 19:12:38 by mzarhou          ###   ########.fr       */
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
	new_arr[i++] = str;
	while (command[i - 1])
	{
		new_arr[i] = command[i - 1];
		i++;
	}
	command = ft_free(command);
	new_arr[i] = NULL;
	return (new_arr);
}
