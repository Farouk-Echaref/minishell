/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:27:18 by fech-cha          #+#    #+#             */
/*   Updated: 2022/06/27 10:22:00 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token *ft_new_token(const char *value, t_type type, int length)
{
    t_token *t;

    t = malloc(sizeof(t_token));
    t->length = length;
    t->type = type;
    t->value = value;
    return (t);
}
