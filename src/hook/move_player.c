/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:15 by yoda              #+#    #+#             */
/*   Updated: 2024/08/23 06:52:19 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

static void	move(t_data *data, t_vector *move_vec)
{
	t_vector	next_pos;

	next_pos.x = data->player.position.x;
	next_pos.y = data->player.position.y + move_vec->y * MOVE_RATE;
	if (next_pos.x >= 0 && next_pos.y >= 0 && next_pos.x < data->map_width
		&& next_pos.y < data->map_height
		&& data->map[(int)next_pos.y][(int)next_pos.x] != WALL
		&& !is_door(data, vector_to_int(next_pos)))
	{
		data->player.position = next_pos;
		return ;
	}
	next_pos.x = data->player.position.x + move_vec->x * MOVE_RATE;
	next_pos.y = data->player.position.y;
	if (next_pos.x >= 0 && next_pos.y >= 0 && next_pos.x < data->map_width
		&& next_pos.y < data->map_height
		&& data->map[(int)next_pos.y][(int)next_pos.x] != WALL
		&& !is_door(data, vector_to_int(next_pos)))
	{
		data->player.position = next_pos;
		return ;
	}
}

void	move_player(t_data *data, t_move_direction direction)
{
	t_vector	next_pos;
	int			move_angle;
	t_vector	move_vec;
	t_collision	obj;

	move_angle = plus_angle(data->player.angle, 0);
	if (direction == BACKWARD)
		move_angle = plus_angle(data->player.angle, 180);
	else if (direction == LEFT)
		move_angle = plus_angle(data->player.angle, 270);
	else if (direction == RIGHT)
		move_angle = plus_angle(data->player.angle, 90);
	angle_to_vector(move_angle, &move_vec);
	cast_ray(data, &obj, move_vec);
	if (calc_distance(&data->player.position, &obj.pos) > MOVE_RATE)
	{
		data->player.position.x += move_vec.x * MOVE_RATE;
		data->player.position.y += move_vec.y * MOVE_RATE;
		return ;
	}
	move(data, &move_vec);
}
