/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:55:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 22:59:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	ft_init_data(t_data *data, char **env)
{
	if (! data)
		return ;
	g_.env = ft_arr_to_list(env);
	g_.exit_status = 0;
	data->tokens = NULL;
	data->tree = NULL;
}
