/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:04:36 by misuzuki          #+#    #+#             */
/*   Updated: 2023/09/25 20:43:16 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			set;
	unsigned char	*copy;

	copy = (unsigned char *)b;
	set = 0;
	while (len > set)
	{
		copy[set] = (unsigned char)c;
		set++;
	}
	return (b);
}
