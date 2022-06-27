/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_each_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:30:52 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 09:39:02 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	ft_each_tree(t_tree *tree, void (*f)(t_tree *))
{
	if (! tree || ! f)
		return ;
	f(tree);
	if (tree->left)
		f(tree->left);
	if (tree->right)
		f(tree->right);
}
