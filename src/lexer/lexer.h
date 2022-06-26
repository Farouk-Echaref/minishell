/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:50 by fech-cha          #+#    #+#             */
/*   Updated: 2022/06/26 06:46:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXER_H
# define LEXER_H
# include "list/list.h"
#include "libft/libft.h"
# include "token/token.h"
# include <stdlib.h>

typedef struct s_lexer
{
    const char  *start;
	const char *content;
	t_list		*tokens;
}	t_lexer;



t_type  ft_get_type(t_lexer *lxr);
t_lexer  *ft_init_lexer(const char *s);
void    ft_destroy_lexer(t_lexer *lxr);
void	ft_lexer(t_lexer *lxr);

#endif
