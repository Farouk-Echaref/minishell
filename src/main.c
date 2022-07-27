/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/27 02:21:10 by mzarhou          ###   ########.fr       */
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

int	main(int argc, char **argv, char **argenv)
{
	t_data	data;
	char	*command_str;
	t_lexer	*lxr;

	command_str = "> file1 > file2 << end ls && < file2 ls >> f20 -al && echo * && echo f*";
	if (argc != 1 || ! argv || ! argenv)
		return (1);
	ft_init_data(&data, argenv);
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
		lxr = ft_init_lexer(command_str);
		data.tokens = ft_lexer(lxr);
		ft_correct_tokens(&data.tokens);
		data.tree = ft_parser(data.tokens);
		ft_evaluator(data.tree);
		ft_destroy_lexer(lxr);
		ft_destroy_data(&data);
		free(command_str);
	}
	ft_lstclear(&g_.env, &free);
}
