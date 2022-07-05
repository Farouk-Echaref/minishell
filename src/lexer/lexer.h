/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:50 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/05 09:57:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "list/list.h"
# include "libft/libft.h"
# include "token/token.h"
# include <stdlib.h>

typedef struct s_lexer
{
	const char	*start;
	const char	*content;
}	t_lexer;

t_lexer	*ft_init_lexer(const char *s);
void	ft_destroy_lexer(t_lexer *lxr);
t_list	*ft_lexer(t_lexer *lxr);
int		ft_is_var(const char *content);

#endif
