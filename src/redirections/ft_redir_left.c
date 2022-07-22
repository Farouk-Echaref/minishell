/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:55 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/22 22:40:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

void ft_redir_left(t_tree *tree, t_evaluator_data *evaluator_data)
{
	char	*file_name;

	if (
		! tree
		|| ! evaluator_data
	)
		return ;
	file_name = ft_get_file_name(tree);
	if (evaluator_data->redirect_left >= 0)
		close(evaluator_data->redirect_left);
	evaluator_data->redirect_left = open(file_name, O_RDONLY);
	if (evaluator_data->redirect_left < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ft_free(file_name);
		exit(1);
	}
	ft_free(file_name);
}
