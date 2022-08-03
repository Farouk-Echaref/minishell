/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/08/03 03:55:17 by mzarhou          ###   ########.fr       */
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

#endif
