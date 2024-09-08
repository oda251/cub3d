/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:20:32 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/24 18:01:45 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			length;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	length = 0;
	while ((*s1_copy != '\0' || *s2_copy != '\0') && length < n)
	{
		if (*s1_copy != *s2_copy)
			return (*s1_copy - *s2_copy);
		s1_copy++;
		s2_copy++;
		length++;
	}
	return (0);
}
