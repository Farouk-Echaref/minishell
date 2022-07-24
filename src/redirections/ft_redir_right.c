/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:52 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 00:05:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

static int	ft_get_file_open_mode(t_tree *node)
{
	t_token	*token;

	if (! node)
		return (0);
	token = node->content;
	if (token->type == REDIR_RIGHT)
		return (O_CREAT | O_TRUNC | O_WRONLY);
	return (O_CREAT | O_APPEND | O_WRONLY);
}

void ft_redir_right(t_tree *tree, t_evaluator_data *evaluator_data)
{
	char	*file_name;
	int		fd;

	if (! tree || ! evaluator_data)
		return ;
	file_name = ft_get_file_name(tree);
	fd = ft_open_file(file_name, ft_get_file_open_mode(tree));
	if (fd > -1)
	{
		if (evaluator_data->redirect_right >= 0)
			close(evaluator_data->redirect_right);
		evaluator_data->redirect_right = fd;
	}
	ft_free(file_name);
}
