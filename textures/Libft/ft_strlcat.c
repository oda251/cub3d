/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:17:42 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/24 21:40:40 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dest_length;
	size_t	i;

	i = 0;
	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	dest_length = ft_strlen(dst);
	if (dest_length >= dstsize)
		return (dstsize + src_length);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && i < dstsize - dest_length - 1)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (dest_length + src_length);
}
