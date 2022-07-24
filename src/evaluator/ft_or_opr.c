/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_opr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:07:47 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 16:19:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"

void	ft_or_opr(t_tree *node)
{
	ft_evaluator(node->left);
	if (g_.exit_status == 0)
		return ;
	ft_evaluator(node->right);
}
