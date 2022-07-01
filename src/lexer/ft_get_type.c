/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/07/01 04:37:42 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_lexer.h"

int	check_type(t_lexer *lxr)
{
	if (ft_get_type_of_char(*(lxr->content + 1)) == VAR)
		return (VAR);
	if ((*(lxr->content + 1)) == '\0')
		return (EXPRESSION);
	if (ft_get_type_of_char(*(lxr->content + 1)) == OTHER)
		return (VAR);
	return (EXPRESSION);
}

int	check_dollar(t_lexer *lxr)
{
	int		move;
	char	*org;

	move = 0;
	org = (char *)lxr->content;
	if (
		*lxr->content == '$' && *(lxr->content + 1) != '$'
		&& *(lxr->content + 1) != '?')
	{
		move = 1;
		if (*lxr->content != '\0')
			lxr->content++;
		while (ft_get_type_of_char(*lxr->content) == OTHER
			&& lxr->content && *lxr->content != '\0'
		)
		{
			lxr->content++;
			move++;
		}
	}
	else
		return (2);
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

t_type	ft_get_type(t_lexer *lxr)
{
	t_type	type;

	if (*lxr->content == '$')
		return (type = check_type(lxr),
			ft_move_content(lxr, check_dollar(lxr)), type);
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
