/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:04:48 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/23 22:05:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_UTILS_H
# define ARR_UTILS_H

# include <stdlib.h>
# include "utils/utils.h"
# include "libft/libft.h"
# include "list/list.h"

void	ft_reverse_arr(char **arr);
int		ft_arr_size(char **arr);
char	**ft_arr_shift(char **command, char *str);
char	**ft_arr_push(char **command, char *str);
char	**ft_arr_free(char **arr);
t_list	*ft_arr_to_list(char **argenv);

#endif
