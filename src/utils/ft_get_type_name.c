/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 03:12:21 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/30 03:13:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_get_type_name(t_type t)
{
	switch (t)
	{
		case COMMAND:
			return "CMD";
		case CMD_OPTION:
			return "CMD_OPT";
		case CMD_ARG:
			return "CMD_ARG";
		case WHITE_SPACE:
			return "SPACE";
		case REDIR_RIGHT:
			return "REDR";
		case REDIR_LEFT:
			return "REDL";
		case SHIFT_LEFT:
			return "SHL";
		case SHIFT_RIGHT:
			return "SHR";
		case AND_OPR:
			return "AND";
		case OR_OPR:
			return "OR";
		case STAR:
			return "STAR";
		case SUB_CMD:
			return "SUB_CMD";
		case SING_QUOT:
			return "SING_Q";
		case DOUB_QUOT:
			return "DOUB_Q";
		case PIPE:
			return "PIPE";
		case VAR:
			return "VAR";
		case FILE_NAME:
			return "FILE_NAME";
		case EXPRESSION:
			return "EXPR";
		default:
			return "OTHER";
	}
}
