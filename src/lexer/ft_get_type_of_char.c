/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_of_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:37:24 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/04 10:31:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

t_type	ft_get_type_of_char(char c)
{
	if (c == ' ')
		return (WHITE_SPACE);
	if (c == '>')
		return (REDIR_RIGHT);
	if (c == '<')
		return (REDIR_LEFT);
	if (c == '|')
		return (REDIR_LEFT);
	if (c == '*')
		return (STAR);
	if (c == '(')
		return (SUB_CMD);
	if (c == '\'')
		return (SING_QUOT);
	if (c == '"')
		return (DOUB_QUOT);
	if (c == '|')
		return (PIPE);
	return (OTHER);
}
