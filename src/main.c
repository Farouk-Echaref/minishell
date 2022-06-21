/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/21 21:41:45 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "token.h"
#include "libft/libft.h"

t_list  *ft_tokonize(char *s)
{
    (void)s;
    return (NULL);
}

int main()
{
    char    *s = "ls -a > test.txt && cat << ts 1> test.txt";
    printf("%p\n", ft_tokonize(s));
}
