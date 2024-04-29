/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:52:14 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 16:25:27 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_digit(long nb, int fd)
{
	char	num;

	if (nb / 10 == 0)
	{
		num = nb % 10 ;
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	ft_putnbr_digit(nb / 10, fd);
	num = nb % 10 ;
	ft_putchar_fd(num + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_digit(nb, fd);
}
