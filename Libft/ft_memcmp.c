/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:38:58 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 14:06:02 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (i < n && *s1_copy == *s2_copy)
	{
		i++;
		s1_copy++;
		s2_copy++;
	}
	if (i == n)
		return (0);
	return ((*s1_copy - *s2_copy));
}
