/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:04:42 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 23:59:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

void	ft_evaluate_redirection(t_tree *tree, t_evaluator_data *evaluator_data)
{
	t_token	*token;

	if (! tree || ! evaluator_data)
		return ;
	token = tree->content;
	if (token->type == REDIR_RIGHT || token->type == SHIFT_RIGHT)
		ft_redir_right(tree, evaluator_data);
	else if (token->type == REDIR_LEFT)
		ft_redir_left(tree, evaluator_data);
}
