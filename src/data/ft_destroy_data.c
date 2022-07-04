/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:54:51 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 19:32:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "token/token.h"

void	ft_destroy_data(t_data *data)
{
	if (! data)
		return ;
	ft_lstclear(&data->tokens, &free);
	ft_tree_clear(&data->tree, &free);
}
