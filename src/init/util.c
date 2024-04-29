/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:10:52 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:18:19 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

char	*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

char	*validate_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_with_message(path, strerror(errno));
	close(fd);
	return (path);
}

char	*omit_line_break(char *line)
{
	char	*str;
	int		i;

	if (!line)
		return (NULL);
	if (ft_strchr(line, '\n') == NULL)
		str = malloc_or_exit(ft_strlen(line) + 1);
	else
		str = malloc_or_exit(ft_strlen(line));
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}
