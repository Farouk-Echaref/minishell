/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:34:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/27 17:36:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "data/data.h"
# include "token/token.h"
# include "lexer/lexer.h"
# include "list/list.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "parser/parser.h"
# include "utils/utils.h"
# include "correction/correction.h"
# include "evaluator/evaluator.h"
# include "signals/signals.h"

void	ft_run_command(char *command_str);

#endif
