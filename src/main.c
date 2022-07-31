/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 02:54:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data/data.h"
#include "token/token.h"
#include "lexer/lexer.h"
#include "list/list.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "parser/parser.h"
#include "utils/utils.h"
#include "correction/correction.h"
#include "evaluator/evaluator.h"
#include "signals/signals.h"
#include "minishell.h"

static void	ft_init(char **env)
{
	g_.env = ft_arr_to_list(env);
	g_.exit_status = 0;
}

int	main(int argc, char **argv, char **argenv)
{

	char	*command_str;

	command_str = "> file1 > file2 ls && < file2 ls >> f20 -al && echo * && echo f*";
	if (argc != 1 || ! argv || ! argenv)
		return (1);
	ft_init(argenv);
	ft_setup_term();
	ft_handle_signals();
	while (1)
	{
		g_.running_status = 1;
		command_str = readline("minishell> ");
		g_.running_status = 0;
		if (command_str == NULL)
			ft_ctrl_d();
		if (ft_strlen(command_str) == 0)
			continue;
		add_history(command_str);
		ft_run_command(command_str);
		free(command_str);
	}
	ft_lstclear(&g_.env, &free);
}
