/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:22:08 by yoda              #+#    #+#             */
/*   Updated: 2024/08/23 06:44:54 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	open_door(t_data *data)
{
	t_collision	obj;
	double		distance;

	cast_ray(data, &obj, data->player.direction);
	distance = calc_distance(&data->player.position, &obj.pos);
	if (distance < 1.415 && is_door(data, obj.obj_pos))
	{
		if (data->door_map[obj.obj_pos.y][obj.obj_pos.x] < MAX_DOOR_STATUS)
			data->door_map[obj.obj_pos.y][obj.obj_pos.x]++;
		if (data->door_map[obj.obj_pos.y][obj.obj_pos.x] == MAX_DOOR_STATUS)
		{
			data->map[obj.obj_pos.y][obj.obj_pos.x] = EMPTY;
			data->door_map[obj.obj_pos.y][obj.obj_pos.x] = 0;
		}
	}
}

void	close_door(t_data *data)
{
	t_collision	obj;
	double		distance;

	cast_ray(data, &obj, data->player.direction);
	distance = calc_distance(&data->player.position, &obj.pos);
	if (distance >= 1.415)
	{
		obj.pos.x = data->player.position.x + data->player.direction.x * 1.415;
		obj.pos.y = data->player.position.y + data->player.direction.y * 1.415;
		if (data->map[(int)obj.pos.y][(int)obj.pos.x] != EMPTY)
			return ;
		data->map[(int)obj.pos.y][(int)obj.pos.x] = DOOR;
		data->door_map[(int)obj.pos.y][(int)obj.pos.x] = 0;
	}
}
