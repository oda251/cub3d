/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:39:35 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 14:10:46 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= len)
		str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (*s && i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	return (str);
}
