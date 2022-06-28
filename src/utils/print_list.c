/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:37:13 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/28 04:46:50 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	ft_print_list(t_list *list)
{
	t_token	*token;
	char	*str;

	while (list)
	{
		token = list->content;
		str = ft_str(token->value, token->length);
		printf("%s ==> (%s)\n", str, ft_get_type_name(token->type));
		free(str);
		list = list->next;
	}
}
