/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:18:44 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/03 21:23:12 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*copy;
	char		*dst2;
	const char	*src2;

	if (dst == NULL && src == NULL)
		return (NULL);
	copy = dst;
	dst2 = (char *)dst;
	src2 = (const char *)src;
	while (n > 0)
	{
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (copy);
}
