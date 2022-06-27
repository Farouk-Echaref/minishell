/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:38:49 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/27 10:48:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "token/token.h"
#include <stdio.h>

#define COUNT 10

static void print2DUtil(t_tree *root, int space)
{
	t_token	*token;

    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
	token = root->content;
    printf("%s\n", ft_str(token->value, token->length));

    print2DUtil(root->left, space);
}

void print2D(t_tree *root)
{
   print2DUtil(root, 0);
}
