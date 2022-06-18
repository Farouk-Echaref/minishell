/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:46:31 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/03 18:55:47 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == INT_MIN)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

// int main()
// {
// 	ft_putnbr_fd(40234, 1);
// 	ft_putstr_fd("\n", 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	ft_putstr_fd("\n", 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putstr_fd("\n", 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putstr_fd("\n", 1);
// 	ft_putnbr_fd(-100, 1);
// 	ft_putstr_fd("\n", 1);
// }
