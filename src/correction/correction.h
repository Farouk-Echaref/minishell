/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 06:45:34 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 02:49:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORRECTION_H
# define CORRECTION_H

# include "list/list.h"
# include "token/token.h"
# include "libft/libft.h"
# include <stdio.h>
# include "evaluator/evaluator.h"
# include <readline/readline.h>
# include <unistd.h>
# include <fcntl.h>

t_list	*ft_move_redirections(t_list *current);
void	ft_merge_expressions_wrapper(t_list **tokens_ptr);
void	ft_rm_redirection_space(t_list *tokens);
void	ft_correct_tokens(t_list **tokens_ptr);
char	*ft_herdoc(t_list *node, int file_count);

#endif
