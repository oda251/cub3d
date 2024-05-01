/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:38:08 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:29:58 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	get_height_width(t_data *data, t_list *map_list);
void	store_line(t_data *data, char *src, int row);
char	read_object(t_data *data, char c, t_vector pos);

void	convert_map(t_data *data, t_list *map_list)
{
	int		i;

	get_height_width(data, map_list);
	data->map = (char **)malloc_or_exit(sizeof(char *) * data->map_height);
	i = -1;
	while (++i < data->map_height)
		data->map[i] = (char *)malloc_or_exit(sizeof(char) * data->map_width);
	data->player.position = (t_vector){-1, -1};
	i = 0;
	while (map_list)
	{
		store_line(data, map_list->content, i);
		map_list = map_list->next;
		i++;
	}
}

char	read_object(t_data *data, char c, t_vector pos)
{
	if (c == ' ')
		return (NONE);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (EMPTY);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (data->player.position.x >= 0)
			exit_with_message(NULL, "Multiple player positions");
		data->player.position = pos;
		if (c == 'N')
			data->player.direction = (t_vector){0, -1};
		else if (c == 'S')
			data->player.direction = (t_vector){0, 1};
		else if (c == 'W')
			data->player.direction = (t_vector){-1, 0};
		else
			data->player.direction = (t_vector){1, 0};
		data->player.radians = vector_to_radians(data->player.direction.x, data->player.direction.y);
		return (EMPTY);
	}
	exit_with_message(NULL, "Invalid character in map");
	return (NONE);
}

void	get_height_width(t_data *data, t_list *map_list)
{
	int		len;
	int		height;
	int		width;

	height = 0;
	width = 0;
	while (map_list)
	{
		height++;
		len = ft_strlen(map_list->content);
		if (len > width)
			width = len;
		map_list = map_list->next;
	}
	if (height < 2 || width < 2)
		exit_with_message(NULL, "Map is too small");
	if (height >= MAX_MAP_SIZE || width >= MAX_MAP_SIZE)
		exit_with_message(NULL, "Map is too large");
	data->map_height = height;
	data->map_width = width;
}

void	store_line(t_data *data, char *src, int row)
{
	int		i;
	int		line_end;

	i = 0;
	line_end = false;
	while (i < data->map_width)
	{
		if (!line_end && src[i] == '\0')
			line_end = true;
		if (line_end)
			data->map[row][i] = NONE;
		else
			data->map[row][i] = read_object(data, src[i], (t_vector){i, row});
		i++;
	}
}
