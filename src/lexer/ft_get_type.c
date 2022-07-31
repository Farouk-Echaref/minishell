/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:18:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/08/01 00:16:16 by mzarhou          ###   ########.fr       */
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

int	check_dollar(t_lexer *lxr)
{
	int		var_length;

	var_length = ft_is_var(lxr->content);
	if (var_length < 2)
	{
		ft_move2_next_token(lxr);
		return (1);
	}
	return (var_length);
}

t_type	ft_matching(t_lexer *lxr)
{
	if (*lxr->content == '(')
		return (ft_handle_diff_matching(lxr, '(', ')'), SUB_CMD);
	if (*lxr->content == '\'')
		return (ft_handle_matching(lxr, '\''), SING_QUOT);
	return (ft_handle_matching(lxr, '"'), DOUB_QUOT);
}

void	ft_(t_lexer *lxr, t_type *type)
{
	if (! type)
		return ;
	*type = EXPRESSION;
	if (ft_is_var(lxr->content) > 1)
		*type = VAR;
}

t_type	ft_get_type(t_lexer *lxr)
{
	t_type	type;

	if (*lxr->content == '$')
		return (ft_(lxr, &type), ft_move_content(lxr, check_dollar(lxr)), type);
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
