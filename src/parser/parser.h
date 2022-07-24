/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/24 20:46:53 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tree/tree.h"
# include "list/list.h"
# include "token/token.h"
# include <stdio.h>
# include "utils/utils.h"

t_tree	*ft_parser(t_list *tokens);
void	ft_cleanup_token(t_token *token);

#endif
