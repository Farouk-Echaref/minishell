/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:34:17 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/27 17:43:51 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_run_command(char *command_str)
{
	t_lexer	*lxr;
	t_data	data;

	data.tokens = NULL;
	data.tree = NULL;
	lxr = ft_init_lexer(command_str);
	data.tokens = ft_lexer(lxr);
	ft_correct_tokens(&data.tokens);
	data.tree = ft_parser(data.tokens);
	ft_evaluator(data.tree);
	ft_destroy_lexer(lxr);
	ft_destroy_data(&data);
}
