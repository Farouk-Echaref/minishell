/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:34:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:47:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "syntax_checker/syntax_checker.h"

void	ft_run_command(char *command_str)
{
	t_lexer	*lxr;
	t_data	data;

	data.tokens = NULL;
	data.tree = NULL;
	lxr = ft_init_lexer(command_str);
	data.tokens = ft_lexer(lxr);
	if (! ft_check_syntax(data.tokens))
	{
		ft_destroy_lexer(lxr);
		ft_lstclear(&data.tokens, &ft_free_token);
		return (ft_putstr_fd("minishell: syntax error\n", 2));
	}
	ft_correct_tokens(&data.tokens);
	data.tree = ft_parser(data.tokens);
	ft_evaluator(data.tree);
	ft_destroy_lexer(lxr);
	ft_destroy_data(&data);
}
