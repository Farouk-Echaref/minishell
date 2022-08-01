/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 05:14:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 05:14:18 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "_lexer.h"

int	ft_var_length(const char *content)
{
	int		len;

	if (! content || *content != '$')
		return (1);
	content++;
	if (*content == '*'
		|| *content == '$'
		|| *content == '?'
		|| ft_isdigit(*content)
	)
		return (2);
	len = 1;
	while (ft_isalnum(*content++) && len++)
		;
	return (len);
}
