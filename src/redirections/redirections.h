/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:22:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 00:54:57 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "evaluator/evaluator.h"
# include <fcntl.h>

char	*ft_get_file_name(t_tree *redirection_node);
void	ft_evaluate_redirection(t_tree *tree, t_evaluator_data *evaluator_data);
void	ft_redir_right(t_tree *tree, t_evaluator_data *evaluator_data);
void	ft_redir_left(t_tree *tree, t_evaluator_data *evaluator_data);
void	ft_shift_left(t_tree *tree, t_evaluator_data *evaluator_data);
void	ft_shift_right(t_tree *tree, t_evaluator_data *evaluator_data);
int		ft_open_file(
			char *file_path,
			int flags,
			t_evaluator_data *evaluator_data
			);

#endif
