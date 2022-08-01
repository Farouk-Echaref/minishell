/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:06:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/31 22:15:42 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "correction.h"

void	ft_set_file_names(t_list *tokens)
{
	while (tokens)
	{
		if (ft_is_redirection(ft_get_token_type(tokens)))
			ft_get_token(tokens->next)->is_filename = 1;
		tokens = tokens->next;
	}
}

void	ft_correct_tokens(t_list **tokens_ptr)
{
	ft_merge_expressions_wrapper(tokens_ptr);
	ft_rm_redirection_space(*tokens_ptr);
	ft_set_file_names(*tokens_ptr);
}
