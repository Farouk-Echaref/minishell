/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:23:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/21 23:24:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*ft_get_token_tree(t_tree *tree)
{
	if (tree)
		return ((t_token *)tree->content);
	return (NULL);
}
