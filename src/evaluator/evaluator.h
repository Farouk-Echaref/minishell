/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:04:50 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/02 07:08:35 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATOR_H
# define EVALUATOR_H

# include "tree/tree.h"
# include "token/token.h"
# include "arr_utils/arr_utils.h"

void	ft_evaluator(t_tree	*tree, char **argenv);

#endif
