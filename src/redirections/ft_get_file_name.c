/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:27:19 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/21 19:27:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

char	*ft_get_file_name(t_tree *redirection_node)
{
	char	*file_name;

	t_token	*filename_token;
	if (! redirection_node || ! redirection_node->right)
		return (NULL);
	filename_token = redirection_node->right->content;
	file_name = ft_str(filename_token->value, filename_token->length);
	return (file_name);
}
