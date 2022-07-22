/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:11:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/21 21:13:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

char	**ft_arr_push(char **command, char *str)
{
	char	**new_arr;
	int		new_size;
	int		i;

	new_size = ft_arr_size(command) + 2;
	new_arr = (char **)malloc(sizeof(char *) * new_size);
	i = 0;
	while (command[i])
	{
		new_arr[i] = command[i];
		i++;
	}
	new_arr[i] = str;
	command = ft_free(command);
	new_arr[i + 1] = NULL;
	return (new_arr);
}
