/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/08/01 03:48:08 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

int	check_whitespace(t_lexer *lxr)
{
	int		move;
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

t_type	ft_matching(t_lexer *lxr)
{
	if (*lxr->content == '(')
		return (ft_handle_diff_matching(lxr, '(', ')'), SUB_CMD);
	if (*lxr->content == '\'')
		return (ft_handle_matching(lxr, '\''), SING_QUOT);
	return (ft_handle_matching(lxr, '"'), DOUB_QUOT);
}

t_type	ft_var_type(t_lexer *lxr)
{
	t_type	type;

	type = EXPRESSION;
	if (ft_var_length(lxr->content) > 1)
		type = VAR;
	ft_move_content(lxr, ft_var_length(lxr->content));
	return (type);
}

t_type	ft_get_type(t_lexer *lxr)
{
	if (*lxr->content == '$')
		return (ft_var_type(lxr));
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
	if (*lxr->content == '(' || *lxr->content == '\'' || *lxr->content == '\"')
		return (ft_matching(lxr));
	if (*lxr->content == '|')
		return (ft_move_content(lxr, 1), PIPE);
	return (ft_move2_next_token(lxr), EXPRESSION);
}
