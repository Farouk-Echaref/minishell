/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 22:33:17 by mzarhou          ###   ########.fr       */
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
	char	*s;
	t_lexer	*lxr;

	s = "> file1 > fie2 << end ls && < f2 ls >> f20 -al";
	if (argc != 1 || ! argv || ! argenv)
		return (1);
	ft_init_data(&data, argenv);
	ft_handle_signals();
	while (1)
	{
		g_.running_status = 1;
		s = readline("minishell> ");
		g_.running_status = 0;
		if (s == NULL)
			ft_ctrl_d();
		if (ft_strlen(s) == 0)
			continue;
		add_history(s);
		lxr = ft_init_lexer(s);
		data.tokens = ft_lexer(lxr);
		ft_correct_tokens(&data.tokens);
		data.tree = ft_parser(data.tokens);
		ft_evaluator_fork(data.tree);
		ft_destroy_lexer(lxr);
		ft_destroy_data(&data);
		free(s);
	}
	ft_lstclear(&g_.env, &free);
}
