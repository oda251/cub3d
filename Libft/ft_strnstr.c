/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:51:00 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/03 21:49:51 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (haystack == NULL && len == 0 && needle != NULL)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] == needle[j] && i < len && haystack[i] != '\0')
		{
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i - j]);
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
