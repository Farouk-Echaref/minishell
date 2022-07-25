/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:04:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 20:06:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATOR_H
# define EVALUATOR_H

# include "tree/tree.h"
# include "token/token.h"
# include "arr_utils/arr_utils.h"
# include "utils/utils.h"
# include "libft/libft.h"
# include <unistd.h>
# include "str_utils/str_utils.h"
# include "lexer/lexer.h"
# include "data/data.h"
# include "builtins/builtins.h"
# include "wildcards/wildcards.h"

typedef struct s_evaluator_data	t_evaluator_data;
struct s_evaluator_data
{
	char	**command;
	int		redirect_right;
	int		redirect_left;
	int		ok;
};

void	ft_expand_expression(t_token *token, t_token *right_token);
void	ft_evaluator(t_tree	*tree);
void	ft_evaluator_no_fork(t_tree	*tree);
void	ft_merge_tokens(t_token *token);
void	ft_expand_double_qoutes(t_token *token);
void	ft_execute(t_evaluator_data *evaluator_data);
char	*ft_evaluate_var(char *var );
void	ft_expand_expression_list(t_list *tokens);
void	ft_init_evaluator_data(t_evaluator_data *data);
void	ft_pipe(t_tree *node);
pid_t	ft_fork();
void	ft_and_opr(t_tree *node);
void	ft_or_opr(t_tree *node);
void	ft_execute_fork(t_evaluator_data *evaluator_data);

#endif
