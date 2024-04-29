/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:16:22 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 16:26:54 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (*src)
	{
		copy[i] = *src;
		src++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
