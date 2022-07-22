/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:04:48 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/21 21:14:26 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_UTILS_H
# define ARR_UTILS_H

# include <stdlib.h>
# include "utils/utils.h"

void	ft_reverse_arr(char **arr);
int		ft_arr_size(char **arr);
char	**ft_arr_shift(char **command, char *str);
char	**ft_arr_push(char **command, char *str);

#endif
