/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/04 20:08:47 by mzarhou          ###   ########.fr       */
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

int	main(int argc, char **argv, char **argenv)
{
	t_data	data;
	char	*s;
	t_lexer	*lxr;

	s = "> file1 > fie2 << end ls && < f2 ls >> f20 -al";
	if (argc != 1 || ! argv)
		return (1);
	ft_init_data(&data);
	while (1)
	{
		s = readline("minishell> ");
		lxr = ft_init_lexer(s);
		data.tokens = ft_lexer(lxr);
		// ft_print_list(data.tokens);
		// printf("=================== merge expressions\n");
		ft_merge_expressions_wrapper(&data.tokens);
		// ft_print_list(data.tokens);
		// printf("=================== move redirections\n");
		data.tokens = ft_move_redirections(data.tokens);
		// ft_print_list(data.tokens);
		// printf("=================== parser\n");
		data.tree = ft_parser(data.tokens);
		// print_tree(data.tree);
		ft_evaluator(data.tree, argenv);
		ft_destroy_lexer(lxr);
		ft_destroy_data(&data);
	}
}
