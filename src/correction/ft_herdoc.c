/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:05:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 00:24:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

char	*ft_expand_line(char *line, t_list *fname_node)
{
	t_token	*token;
	char	*str;
	t_token	*fname_token;

	if (! fname_node)
		return (ft_strdup(line));
	fname_token = ft_get_token(fname_node);
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

void	ft_herdoc(t_list *node, const char *file_name)
{
	int		fd;
	char	*stop_message;
	char	*line;

	if (! node || ! node->next)
		return ;
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	stop_message = ft_str(
		ft_get_token(node->next)->value,
		ft_get_token(node->next)->length
	);
	if (fd < 0 || ! stop_message)
		return free(stop_message);
	while (1)
	{
		line = readline("> ");
		if ((! line || ft_strcmp(line, stop_message) == 0) && ! ft_free(line))
			break ;
		line = ft_assign_free(&line, ft_expand_line(line, node->next));
		ft_write_ln(fd, line);
		line = ft_free(line);
	}
	close(fd);
	stop_message = ft_free(stop_message);
}
