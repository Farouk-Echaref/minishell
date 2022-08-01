/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 22:21:53 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include <readline/readline.h>

char	*ft_expand_line(char *line, t_tree *fname_node)
{
	t_token	*token;
	char	*str;
	t_token	*fname_token;

	if (! fname_node)
		return (ft_strdup(line));
	fname_token = ft_get_token_tree(fname_node);
	if (
		fname_token->is_herdoc_expr_list
		|| fname_token->type == SING_QUOT
		|| fname_token->type == DOUB_QUOT
	)
		return (ft_strdup(line));
	token = ft_new_token(ft_strdup(line), EXPRESSION, ft_strlen(line));
	ft_expand_double_qoutes(token);
	str = ft_strdup(token->value);
	ft_free_token(token);
	return (str);
}

void	ft_write_ln(int fd, char *line)
{
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

void	ft_shift_left(t_tree *tree, t_evaluator_data *evaluator_data)
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
		if ((! line || ft_strcmp(line, stop_message) == 0) && ! ft_free(line))
			break ;
		line = ft_assign_free(&line, ft_expand_line(line, tree->right));
		ft_write_ln(fd, line);
		line = ft_free(line);
	}
	close(fd);
	fd = open(file_name, O_RDONLY, 0644);
	if (fd > 0)
		evaluator_data->redirect_left = fd;
}
