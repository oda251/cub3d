/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:16:21 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 01:49:53 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

char	*parse_tex_path(char *line)
{
	char	*path;

	line += 2;
	line = skip_spaces(line);
	path = ft_strdup(line);
	if (!path)
		exit_with_message("ft_strdup", strerror(errno));
	return (validate_path(path));
}

static void	store_color(t_rgbo *color, int i, char prm)
{
	char	*cur;

	cur = (char *)color;
	cur[i] = prm;
}

t_rgbo	parse_color(char *line)
{
	t_rgbo			color;
	int				prm;
	unsigned char	i;

	line += 1;
	i = 0;
	while (*line)
	{
		prm = 0;
		line = skip_spaces(line);
		while (ft_isdigit(*line))
		{
			prm = prm * 10 + *line - '0';
			if (prm > 255)
				exit_with_message(NULL, "Invalid color parameter");
			line++;
		}
		line = skip_spaces(line);
		if ((i < 2 && *line != ',') || (i == 2 && *line))
			exit_with_message(NULL, "Invalid color parameter");
		store_color(&color, i, prm);
		if (i++ < 2)
			line++;
	}
	return (color);
}
