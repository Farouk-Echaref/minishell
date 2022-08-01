/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:38:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:32:59 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H

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
# include <sys/types.h>
# include <dirent.h>
# include "errors/errors.h"
# include "evaluator/evaluator.h"

t_list	*ft_get_file_names(void);
char	*ft_lstjoin_matches(t_list *lst);
int		ft_expand_wildcard(t_token *token, int is_redirection);
int		ft_expand_star_list(t_token *token,
			int is_redirection, int *is_ambiguous_redirection_status);
t_list	*ft_split_pattern(t_list *lst);

#endif
