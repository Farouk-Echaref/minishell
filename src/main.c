/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:16:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/06/20 21:02:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

typedef enum e_type	t_type;
typedef struct s_token	t_token;

enum	e_type
{
	e_operator = 1,
	e_command
};

struct	s_token
{
	t_type	type;
	char	*value;
	int		length;
};


t_list	*ft_tokonize(char *s)
{
	(void)s;
	return (NULL);
}

int main()
{
	char	*s = "ls -a > test.txt && cat << ts 1> test.txt";
	printf("%p\n", ft_tokonize(s));
}
