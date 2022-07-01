/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:06:02 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/01 08:44:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluator.h"
#include <stdio.h>
#include "utils/utils.h"
#include "libft/libft.h"

char	*command = NULL;

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

static int	ft_arr_size(char **arr)
{
	int	count;

	count = 0;
	while (arr[count++]);
	return (count - 1);
}

void	ft_reverse_arr(char **arr)
{
	int		i;
	int		j;
	char	*str;

	if (! arr)
		return ;
	j = ft_arr_size(arr) - 1;
	i = 0;
	while (i < j)
	{
		str = arr[i];
		arr[i] = arr[j];
		arr[j] = str;
		i++;
		j--;
	}
}

static void ft_join_expressions(char *expr)
{
	char	*temp;

	if (! command)
		command = ft_strdup("");
    temp = command;
	if (expr)
	{
		command = ft_strjoin(command, " ");
		temp = ft_free(temp);
        temp = command;
		command = ft_strjoin(command, expr);
	}
	temp = ft_free(temp);
}

void    ft_parse_command()
{
    char    **arr;

    if (! command)
        return ;
    arr = ft_split(command, ' ');
    ft_reverse_arr(arr);
	command = ft_free(command);
	command = NULL;
    int i = 0;
    while (arr && arr[i])
    {
        ft_join_expressions(arr[i]);
        i++;
    }
    printf("---> %s\n", command);
	command = ft_free(command);
}

void	ft_evaluator(t_tree	*tree, char **argenv)
{
	t_token	*token;
	char	*str;

	if (! tree || ! argenv)
	{
        ft_parse_command();
		return ;
	}
	token = tree->content;
	str = ft_str(token->value, token->length);
	ft_join_expressions(str);
	str = ft_free(str);
	ft_evaluator(tree->left, argenv);
}
