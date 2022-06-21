/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:49:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/22 00:07:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft/libft.h"
#include "token.h"
#include <stdlib.h>

t_lexer  *ft_init_lexer(const char *s)
{
    t_lexer *lxr;

    lxr = (t_lexer *)malloc(sizeof(t_lexer));
    lxr->start = s;
    lxr->content = s;
    return (lxr);
}

void    ft_destroy_lexer(t_lexer *lxr)
{
    if (! lxr)
        return ;
    free(lxr);
}

t_list    *ft_lexer(t_lexer *lxr)
{
    t_type  type;
    char    *value;
    int     len;

    while (lxr->content && *lxr->content)
    {
        value = lxr->content;
        type = ft_get_type(lxr);
        len = lxr->content - value;
    }
}
