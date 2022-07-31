/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:17:51 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/30 02:23:07 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define AMBIGUOUS_MESSAGE "ambiguous redirect"

# include "libft/libft.h"

void	ft_error_message(char *key, char *error_message);

#endif
