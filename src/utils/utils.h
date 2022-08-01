/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:38:56 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/01 01:38:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tree/tree.h"
# include "token/token.h"
# include <stdio.h>
# include <stdlib.h>

char	*ft_str(const char *s, int len);
char	*ft_get_type_name(t_type t);
void	ft_print_list(t_list *list);
void	ft_print_list_values(t_list *list);
void	ft_print_list_values_reverse(t_list *list);
char	*ft_get_type_name(t_type t);
void	*ft_free(void *ptr);
void	ft_print_tokens_list(t_token *token);
int		ft_isvalidnumber(char *s);
void	ft_print_lst(t_list *lst);
void	ft_print_token_value_ln(t_token *token);
void	ft_print_token_value(t_token *token);
char	*ft_assign_free(char **value_to_free, char *new_value);

#endif
