/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:11:14 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/18 01:15:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char const *s2, size_t size)
{
	char	*dest;
	size_t	i;
	size_t	total;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + size;
	dest = malloc((1 + total) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (*s2 && i < total)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
