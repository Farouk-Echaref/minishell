/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:36:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/05 10:45:58 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "_lexer.h"

int	ft_is_var(const char *content)
{
	int		len;

	if (! content || *content != '$')
		return (1);
	content++;
	if (*content == '*' || *content == '$' || *content == '?')
		return (2);
	len = 1;
	while (ft_isalnum(*content++) && len++)
		;
	return (len);
}
