/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:18:33 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 02:23:13 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_rgbo	get_object_color(t_object object)
{
	t_rgbo	color;

	color = 0;
	if (object == DOOR_OPEN)
		color = 0x00FF00AA;
	else if (object == EMPTY)
		color = 0xFFFFFFAA;
	else if (object == WALL)
		color = 0xFF0000AA;
	else if (object == DOOR_CLOSED)
		color = 0x0000FFAA;
	else if (object == PLAYER)
		color = 0x00FFFFAA;
	return (color);
}

void	put_tile(t_data *data, t_vector_int minimap_cur, t_object object)
{
	const t_vector_int	start = {
		minimap_cur.x * MINIMAP_TILE_SIZE,
		minimap_cur.y * MINIMAP_TILE_SIZE
	};
	t_vector_int		cur;

	cur.y = -1;
	while (++cur.y < MINIMAP_TILE_SIZE)
	{
		cur.x = -1;
		while (++cur.x < MINIMAP_TILE_SIZE)
			put_pixel(data,
				(t_vector_int){start.x + cur.x, start.y + cur.y},
				get_object_color(object));
	}
}

void	render_minimap(t_data *data)
{
	t_vector_int	cur;
	t_vector_int	cur_on_map;
	t_object		object;

	cur.y = -1;
	while (++cur.y < MINIMAP_SIZE)
	{
		cur.x = -1;
		while (++cur.x < MINIMAP_SIZE)
		{
			cur_on_map.y = cur.y + (int) data->player.position.y - MINIMAP_SIZE / 2;
			cur_on_map.x = cur.x + (int) data->player.position.x - MINIMAP_SIZE / 2;
			if (cur_on_map.y == (int) data->player.position.y
				&& cur_on_map.x == (int) data->player.position.x)
				object = PLAYER;
			else if (cur_on_map.y < 0 || cur_on_map.y >= data->map_height
				|| cur_on_map.x < 0 || cur_on_map.x >= data->map_width)
				object = NONE;
			else
				object = data->map[cur_on_map.y][cur_on_map.x];
			put_tile(data, cur, object);
		}
	}
}
