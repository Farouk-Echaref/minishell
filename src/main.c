/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/30 04:47:53 by mzarhou          ###   ########.fr       */
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

int main()
{
	t_data	data;
	char	*s = "> f2 ls > f1 -al | grep > f1s";
	t_lexer	*lxr;

	ft_init_data(&data);
	while (1)
	{
		s = readline("minishell> ");
		lxr = ft_init_lexer(s);
		data.tokens = ft_lexer(lxr);
		data.tokens = ft_move_redirections(data.tokens);
		// ft_print_list_values(data.tokens);
		// ft_print_list_values_reverse(data.tokens);
		data.tree = ft_parser(data.tokens);
		print_tree(data.tree);
		// ft_print_list(data.tokens);
		ft_destroy_lexer(lxr);
		ft_destroy_data(&data);
	}
}
