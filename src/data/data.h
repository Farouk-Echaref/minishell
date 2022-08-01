/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:54:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 23:10:02 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "list/list.h"
# include "tree/tree.h"
# include <stdlib.h>
# include "arr_utils/arr_utils.h"

struct s_
{
	int		exit_status;
	int		running_status;
	t_list	*env;
} g_;

// single source of truth
typedef struct s_data	t_data;

struct s_data
{
	t_list			*tokens;
	struct s_tree	*tree;
};

void	ft_destroy_data(t_data *data);
void	ft_init_data(t_data *data, char **env);

#endif
