/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:05:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 04:31:26 by mzarhou          ###   ########.fr       */
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
	token = ft_new_token(ft_strdup(line), EXPRESSION);
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

char	*ft_get_stop_message(t_list *node)
{
	t_token	*t;
	char	*stop_message;
	int		i;
	int		j;

	t = ft_get_token(node);
	stop_message = (char *)malloc(ft_strlen(t->value) + 1);
	i = 0;
	j = 0;
	while (t->value && ((char *)t->value)[i])
	{
		if (
			((char *)t->value)[i] != '\''
			&& ((char *)t->value)[i] != '"'
		)
			stop_message[j++] = ((char *)t->value)[i];
		i++;
	}
	stop_message[j] = 0;
	return (stop_message);
}

char	*ft_herdoc(t_list *node, int file_count)
{
	int			fd;
	char		*stop_message;
	char		*line;
	char		*file_name;

	file_name = ft_strdup("/tmp/.herdoc ");
	if (! node || ! node->next)
		return (file_name);
	file_name[ft_strlen(file_name) - 1] = file_count + '0';
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	stop_message = ft_get_stop_message(node->next);
	if (fd < 0 || ! stop_message)
		return (free(stop_message), file_name);
	while (1)
	{
		line = readline("> ");
		if ((! line || ft_strcmp(line, stop_message) == 0) && ! ft_free(line))
			break ;
		line = ft_assign_free(&line, ft_expand_line(line, node->next));
		ft_write_ln(fd, line);
		line = ft_free(line);
	}
	return (close(fd), ft_free(stop_message), file_name);
}
