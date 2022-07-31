/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:37:18 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:52:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_assign_free(char **value_to_free, char *new_value)
{
	if (value_to_free && *value_to_free)
		*value_to_free = ft_free(*value_to_free);
	return (new_value);
}
