/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:38:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 19:25:22 by mzarhou          ###   ########.fr       */
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

t_list	*ft_get_file_names();
int ft_match(const char *pattern, const char *file_name, int p, int f);
t_list	*ft_get_matches(t_list *file_names, t_token *token);
char	*ft_lstjoin_matches(t_list *lst);
void	ft_expand_wildcard(t_token *token);
void	ft_expand_star_list(t_token *token);

#endif
