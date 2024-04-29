/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:40:26 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/28 03:22:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_arr(const char *s, char *arr)
{
	char	*tmp;

	while (*s)
	{
		tmp = arr;
		while (*tmp)
		{
			if (*s == *tmp)
				return ((char *)s);
			tmp++;
		}
		s++;
	}
	tmp = arr;
	while (*tmp)
	{
		if (*s == *tmp)
			return ((char *)s);
		tmp++;
	}
	return (NULL);
}
