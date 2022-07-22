/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_evaluator_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:57:16 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 11:59:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_init_evaluator_data(t_evaluator_data *data)
{
	if (! data)
		return ;
	data->command = (char **)malloc(sizeof(char *));
	*data->command = NULL;
	data->redirect_right = -1;
	data->redirect_left = -1;
}
