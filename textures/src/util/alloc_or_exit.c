/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_or_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:02:01 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 17:59:53 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

void	*malloc_or_exit(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_with_message("malloc", strerror(errno));
	return (ptr);
}

void	*calloc_or_exit(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		exit_with_message("calloc", strerror(errno));
	return (ptr);
}

char	*strdup_or_exit(char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
		exit_with_message("strdup", strerror(errno));
	return (dup);
}
