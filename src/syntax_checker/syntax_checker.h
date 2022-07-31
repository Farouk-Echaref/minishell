/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:23:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 01:39:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_CHECKER_H
# define SYNTAX_CHECKER_H

#include <stdio.h>
#include "data/data.h"
#include "token/token.h"
#include "lexer/lexer.h"
#include "list/list.h"
#include "parser/parser.h"
#include "utils/utils.h"
#include "correction/correction.h"
#include "evaluator/evaluator.h"
#include "signals/signals.h"
#include "minishell.h"

typedef enum e_direction t_direction;

enum e_direction
{
	LEFT,
	RIGHT
};

int	ft_check_syntax(t_list *tokens);

#endif
