/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 21:59:32 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include <readline/readline.h>

char	*ft_expand_line(char *line)
{
	t_token	*token;

	token = ft_new_token(line, EXPRESSION, ft_strlen(line));
	ft_expand_double_qoutes(token);
	return (token->value);
}

void ft_shift_left(t_tree *tree, t_evaluator_data *evaluator_data)
{
	int		fd;
	char	*stop_message;
	char	*line;
	char	*file_name;

	if (! tree || ! tree->right)
		return ;
	file_name = "/tmp/.heredocument";
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	stop_message = ft_get_token_tree(tree->right)->value;
	if (fd < 0 || ! stop_message)
		return ;
	while (1)
	{
		line = readline("> ");
		if (! line || ft_strcmp(line, stop_message) == 0)
			break ;
		line = ft_expand_line(line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
        line = ft_free(line);
	}
	line = ft_free(line);
	if (fd < 0)
		return ;
	close(fd);
	fd = open(file_name, O_RDONLY, 0644);
	if (fd > 0)
		evaluator_data->redirect_left = fd;
}
