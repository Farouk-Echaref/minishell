/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:18:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/02 22:52:54 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "data/data.h"
# include "list/list.h"
# include "libft/libft.h"
# include "str_utils/str_utils.h"

t_list	*ft_search_env(char *var_name);
char	*ft_make_env_line(char *var_name, char *value);
void	ft_sort(char **args, int size);
void	ft_add_env(char *var_name, char *value, int concat);
char	*ft_get_var_name(char *arg, int *concat);
char	*ft_var_value(char *line);

#endif
