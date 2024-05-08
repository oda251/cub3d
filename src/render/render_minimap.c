/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:18:33 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 17:56:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_rgb	get_object_color(t_object object)
{
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	if (object == DOOR_OPEN)
		color = (t_rgb){0, 255, 0};
	else if (object == EMPTY)
		color = (t_rgb){255, 255, 255};
	else if (object == WALL)
		color = (t_rgb){255, 0, 0};
	else if (object == DOOR_CLOSED)
		color = (t_rgb){0, 0, 255};
	else if (object == PLAYER)
		color = (t_rgb){0, 255, 255};
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
