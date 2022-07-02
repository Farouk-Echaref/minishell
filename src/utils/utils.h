/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:38:56 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 07:10:32 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tree/tree.h"
# include "token/token.h"
# include <stdio.h>
# include <stdlib.h>

void	print_tree(t_tree *root);
char	*ft_str(const char *s, int len);

char	*ft_get_type_name(t_type t);
void	ft_print_list(t_list *list);
void	ft_print_list_values(t_list *list);
void	ft_print_list_values_reverse(t_list *list);
char	*ft_get_type_name(t_type t);
void	*ft_free(void *ptr);

#endif
