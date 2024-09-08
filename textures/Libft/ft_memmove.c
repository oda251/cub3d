/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:58:06 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 13:59:26 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_copy = (unsigned char *)dst;
	src_copy = (unsigned char *)src;
	i = 0;
	if (dst_copy < src_copy)
	{
		while (i < len)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
		return ((void *)dst_copy);
	}
	while (len > 0)
	{
		len--;
		dst_copy[len] = src_copy[len];
	}
	return ((void *)dst_copy);
}
