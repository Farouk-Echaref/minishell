/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:55:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/22 23:11:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	ft_init_data(t_data *data)
{
	if (! data)
		return ;
	g_exit_status = 1;
	data->tokens = NULL;
	data->tree = NULL;
}
