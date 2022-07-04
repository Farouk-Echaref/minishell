/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:36:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 10:54:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

int	ft_is_var(const char *content)
{
	char	c;

	if (! content || *content != '$')
		return (0);
	c = *(content + 1);
	if (c && ft_get_type_of_char(c) == OTHER)
		return (1);
	return (0);
}
