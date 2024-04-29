/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:48:29 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/24 18:01:28 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (*src && len > 0)
	{
		copy[i] = *src;
		src++;
		i++;
		len--;
	}
	copy[i] = '\0';
	return (copy);
}
