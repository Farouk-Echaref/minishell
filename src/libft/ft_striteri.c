/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:20:48 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/07 16:01:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	t(unsigned int index, char *c)
// {
// 	index = 0;
// 	*c += 1;
// }

// int main()
// {
// 	char s[] = "Mohamed";
// 	ft_striteri(s, t);
// 	ft_putstr_fd(s, 1);
// 	ft_putchar_fd('\n', 1);
// }
