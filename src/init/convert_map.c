/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:38:08 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:42:23 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	get_height_width(t_data *data, t_list *map_list);
void	store_line(t_data *data, char *src, int row);
char	read_object(t_data *data, char c, t_vector_int pos);
char	set_player(t_data *data, char c, t_vector_int pos);

void	convert_map(t_data *data, t_list *map_list)
{
	int		i;

	get_height_width(data, map_list);
	data->map = (char **)calloc_or_exit(sizeof(char *), data->map_height);
	data->door_map = (char **)calloc_or_exit(sizeof(char *), data->map_height);
	i = -1;
	while (++i < data->map_height)
	{
		data->map[i] = (char *)calloc_or_exit(sizeof(char), data->map_width);
		data->door_map[i] = (char *)calloc_or_exit(sizeof(char), data->map_width);
	}
	data->player.position = (t_vector){-1, -1};
	i = 0;
	while (map_list)
	{
		store_line(data, map_list->content, i);
		map_list = map_list->next;
		i++;
	}
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
			data->map[row][i] = read_object(data, src[i], (t_vector_int){i, row});
		i++;
	}
}

char	read_object(t_data *data, char c, t_vector_int pos)
{
	t_door	*door;
	t_list	*new;

	if (c == ' ')
		return (NONE);
	else if (c == '1')
		return (WALL);
	else if (c == '0')
		return (EMPTY);
	else if (c == 'D')
	{
		door = (t_door *)malloc_or_exit(sizeof(t_door));
		door->pos = pos;
		new = ft_lstnew(door);
		if (!new)
			exit_with_message(NULL, "Failed to allocate memory");
		ft_lstadd_back(&data->doors, new);
		return (DOOR);
	}
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (set_player(data, c, pos));
	return (exit_with_message(NULL, "Invalid character in map"), NONE);
}

char	set_player(t_data *data, char c, t_vector_int pos)
{
	if (data->player.position.x >= 0)
		exit_with_message(NULL, "Multiple player detected");
	data->player.position.x = pos.x + 0.5;
	data->player.position.y = pos.y + 0.5;
	if (c == 'N')
		data->player.angle = 90;
	else if (c == 'S')
		data->player.angle = 270;
	else if (c == 'W')
		data->player.angle = 180;
	else if (c == 'E')
		data->player.angle = 0;
	angle_to_vector(data->player.angle, &data->player.direction);
	return (EMPTY);
}