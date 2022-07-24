/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:06:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/06 13:10:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

void	ft_correct_tokens(t_list **tokens_ptr)
{
		ft_merge_expressions_wrapper(tokens_ptr);
		ft_rm_redirection_space(*tokens_ptr);
		*tokens_ptr = ft_move_redirections(*tokens_ptr);
}
