/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:39:22 by misuzuki          #+#    #+#             */
/*   Updated: 2024/04/29 02:06:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (sign * result <= (LONG_MAX - (*str - '0')) / 10 && sign
			* result >= (LONG_MIN + (*str - '0')) / 10)
			result = result * 10 + (*str - '0');
		else if (sign == 1)
			return ((int)LONG_MAX);
		else
			return ((int)LONG_MIN);
		str++;
	}
	return ((int)(sign * result));
}
