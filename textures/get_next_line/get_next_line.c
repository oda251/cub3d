/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:54:07 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 02:30:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	logs[OPEN_MAX - _SC_OPEN_MAX] = {{0}};
	t_gnl			dest;
	char			*buf;

	if (!initialize_gnl(fd, &dest, &buf, &logs[fd]))
		return (NULL);
	if (!cat_to_line_break(&dest, logs[fd].str, &logs[fd], logs[fd].len)
		|| search_line_break(dest.str, BUFFER_SIZE))
	{
		free(buf);
		return (dest.str);
	}
	solve_get_next_line(fd, &dest, buf, &logs[fd]);
	free(buf);
	if (!dest.str || !dest.len)
	{
		if (dest.str && !dest.len)
			free(dest.str);
		free(logs[fd].str);
		logs[fd].str = NULL;
		return (NULL);
	}
	return (dest.str);
}
