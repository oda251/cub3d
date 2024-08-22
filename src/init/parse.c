/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:16:21 by yoda              #+#    #+#             */
/*   Updated: 2024/08/23 05:59:31 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

char	*parse_tex_path(char *line)
{
	char	*path;

	while (*line && *line != ' ')
		line++;
	if (!*line)
		exit_with_message(NULL, "Invalid texture path");
	line = skip_spaces(line);
	path = ft_strdup(line);
	if (!path)
		exit_with_message("ft_strdup", strerror(errno));
	return (validate_path(path));
}

t_rgbo	parse_color(char *line)
{
	t_rgbo			color;
	int				prm;
	unsigned char	i;

	line += 1;
	i = 0;
	color = 0x000000FF;
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
		if ((i < 2 && *line != ',') || (i == 2 && *line))
			exit_with_message(NULL, "Invalid color parameter");
		((uint8_t *)&color)[2 - i] = (uint8_t)prm;
		if (i++ < 2)
			line++;
	}
	return (color);
}
