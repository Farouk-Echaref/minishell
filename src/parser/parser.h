/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:42:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 20:12:46 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tree/tree.h"
# include "list/list.h"

t_tree	*ft_parser(t_list *tokens);
void	ft_commandify(t_list	*tokens);

#endif
