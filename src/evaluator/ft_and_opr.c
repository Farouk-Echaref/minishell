/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_opr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:33:22 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:13:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_and_opr(t_tree *node)
{
	ft_evaluator(node->left);
	if (g_.exit_status != 0)
		return ;
	ft_evaluator(node->right);
}
