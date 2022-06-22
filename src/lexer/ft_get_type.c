/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/06/22 07:43:22 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_move_content(t_lexer *lxr, int length)
{
	lxr->content += length;
}

t_type  ft_get_type_of_char(char c)
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
        return (LEFT_PAR);
    if (c == ')')
        return (RIGHT_PAR);
    if (c == '\'')
        return (SING_QUOT);
    if (c == '"')
        return (DOUB_QUOT);
    if (c == '|')
        return (PIPE);
	if (c == '$')
		return (VAR);
	return (OTHER);
}

void	ft_move2_next_token(t_lexer *lxr)
{
	while (lxr->content && *lxr->content && ft_get_type_of_char(*lxr->content) == OTHER)
		lxr->content++;
}

int	check_whitespace(t_lexer *lxr)
{
	int	move;
	char	*org;

	move = 0;
	org = (char *)lxr->content;
	if (*lxr->content == ' ')
	{
		while (*lxr->content == ' ')
		{
			lxr->content++;
			move++;
		}
	}
	lxr->content = org;
	return (move);
}

int check_type(t_lexer *lxr)
{
	if (ft_get_type_of_char(*(lxr->content+1)) == VAR)
		return (VAR);
	if ((*(lxr->content+1)) == '\0')
	 	return (EXPRESSION);
	if (ft_get_type_of_char(*(lxr->content+1)) == OTHER)
	 	return (VAR);
	return (EXPRESSION);
}

int	check_dollar(t_lexer *lxr)
{
	int	move;
	char	*org;

	move = 0;
	org = (char *)lxr->content;
	if (*lxr->content == '$' && *(lxr->content + 1) != '$')
	{
		move = 1;
		if (*lxr->content != '\0')
			lxr->content++;
		while (ft_get_type_of_char(*lxr->content) == OTHER && lxr->content && *lxr->content != '\0')
		{
			lxr->content++;
			move++;
		}
	} else
		return (2);
	lxr->content = org;
	return (move);
}

t_type  ft_get_type(t_lexer *lxr)
{
	t_type type;

	if (*lxr->content == '$')
	{
		type = check_type(lxr);
		return (ft_move_content(lxr, check_dollar(lxr)),type);
	}
	if (*lxr->content == ' ')
        return (ft_move_content(lxr, check_whitespace(lxr)), WHITE_SPACE);
	if (ft_strncmp(lxr->content, "<<", 2) == 0)
        return (ft_move_content(lxr, 2), SHIFT_LEFT);
    if (ft_strncmp(lxr->content, ">>", 2) == 0)
        return (ft_move_content(lxr, 2), SHIFT_RIGHT);
    if (ft_strncmp(lxr->content, "&&", 2) == 0)
        return (ft_move_content(lxr, 2), AND_OPR);
    if (ft_strncmp(lxr->content, "||", 2) == 0)
        return (ft_move_content(lxr, 2), OR_OPR);
    if (*lxr->content == '>')
        return (ft_move_content(lxr, 1), REDIR_RIGHT);
    if (*lxr->content == '<')
        return (ft_move_content(lxr, 1), REDIR_LEFT);
    if (*lxr->content == '*')
        return (ft_move_content(lxr, 1), STAR);
    if (*lxr->content == '(')
        return (ft_move_content(lxr, 1), LEFT_PAR);
    if (*lxr->content == ')')
        return (ft_move_content(lxr, 1), RIGHT_PAR);
    if (*lxr->content == '\'')
        return (ft_move_content(lxr, 1), SING_QUOT);
    if (*lxr->content == '"')
        return (ft_move_content(lxr, 1), DOUB_QUOT);
    if (*lxr->content == '|')
        return (ft_move_content(lxr, 1), PIPE);
	return (ft_move2_next_token(lxr), EXPRESSION);
}
