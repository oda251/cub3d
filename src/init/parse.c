/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:16:21 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:25:29 by yoda             ###   ########.fr       */
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

uint32_t encode_rgba(t_rgb *color)
{
	int r;
	int g;
	int b;

	r = color->r;
	g = color->g;
	b = color->b;
    return ((r << 24) | (g << 16) | (b << 8));
}

static void	store_color(t_rgb *color, int i, int prm)
{
	if (i == 0)
		color->r = prm;
	else if (i == 1)
		color->g = prm;
	else
		color->b = prm;
}

t_rgb	*parse_color(char *line)
{
	t_rgb			*color;
	int				prm;
	unsigned char	i;

	line += 1;
	color = (t_rgb *)malloc_or_exit(sizeof(t_rgb));
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
		store_color(color, i, prm);
		if (i++ < 2)
			line++;
	}
	return (color);
}
