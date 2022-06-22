/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/06/22 07:30:19 by mzarhou          ###   ########.fr       */
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
        return (SUB_CMD);
    if (c == '\'')
        return (SING_QUOT);
    if (c == '"')
        return (DOUB_QUOT);
    if (c == '|')
        return (PIPE);
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
	char *org;

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

void	ft_handle_matching(t_lexer *lxr, char c)
{
	char	*matching;

	matching = ft_strchr(lxr->content + 1, c);
	if (matching != NULL)
		ft_move_content(lxr, matching - lxr->content + 1);
	else
		ft_move_content(lxr, 1);
}

void	ft_handle_diff_matching(t_lexer *lxr, char opening_match, char closing_match)
{
	int			i;
	const char	*s;

	i = 1;
	s = lxr->content + 1;
	while (s && *s)
	{
		if (*s == opening_match)
			i++;
		else if (*s == closing_match)
			i--;
		if (i == 0)
			return (ft_move_content(lxr, s - lxr->content + 1));
		s++;
	}
	ft_move_content(lxr, 1);
}

t_type  ft_get_type(t_lexer *lxr)
{
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
		return (ft_handle_diff_matching(lxr, '(', ')'), SUB_CMD);
    if (*lxr->content == '\'')
		return (ft_handle_matching(lxr, '\''), SING_QUOT);
    if (*lxr->content == '"')
		return (ft_handle_matching(lxr, '"'), DOUB_QUOT);
    if (*lxr->content == '|')
        return (ft_move_content(lxr, 1), PIPE);
	return (ft_move2_next_token(lxr), EXPRESSION);
}
