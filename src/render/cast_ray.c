/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 06:01:29 by oda251            #+#    #+#             */
/*   Updated: 2024/08/23 06:41:31 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	find_object_x(
	t_data *data, t_vector_int *point, t_collision *obj)
{
	obj->obj_facing_to = WEST;
	if (point->x - 1 >= 0 && obj->obj_type != WALL && !is_door(data, *point))
	{
		obj->obj_type = data->map[point->y][point->x - 1];
		obj->obj_facing_to = EAST;
		obj->obj_pos.x = point->x - 1;
	}
}

static t_collision	find_object(t_data *data, t_vector cur)
{
	t_vector_int	point;
	t_collision		obj;

	point = vector_to_int(cur);
	obj.obj_pos = point;
	obj.obj_type = data->map[point.y][point.x];
	if (cur.x == floor(cur.x))
		find_object_x(data, &point, &obj);
	else
	{
		obj.obj_facing_to = NORTH;
		if (point.y - 1 >= 0 && obj.obj_type != WALL && !is_door(data, point))
		{
			obj.obj_type = data->map[point.y - 1][point.x];
			obj.obj_facing_to = SOUTH;
			obj.obj_pos.y = point.y - 1;
		}
	}
	return (obj);
}

static void	calc_obj_vars(
	t_collision *obj, t_player *player)
{
	if (obj->obj_facing_to == WEST)
		obj->wall_x = obj->pos.y - floor(obj->pos.y);
	else if (obj->obj_facing_to == EAST)
		obj->wall_x = ceil(obj->pos.y) - obj->pos.y;
	else if (obj->obj_facing_to == SOUTH)
		obj->wall_x = obj->pos.x - floor(obj->pos.x);
	else
		obj->wall_x = ceil(obj->pos.x) - obj->pos.x;
	while (obj->wall_x >= 1)
		obj->wall_x -= 1;
	while (obj->wall_x < 0)
		obj->wall_x += 1;
	obj->distance = fabs(
			player->direction.x * (player->position.x - obj->pos.x)
			+ player->direction.y * (player->position.y - obj->pos.y)
			);
}

void	cast_ray(t_data *data, t_collision *dst, t_vector direction)
{
	t_dda			dda;
	t_vector		cur;
	t_collision		obj;

	init_dda(data, &dda, &direction);
	while (true)
	{
		cur = proceed_dda(&dda);
		obj = find_object(data, cur);
		if (obj.obj_type == WALL || is_door(data, obj.obj_pos))
		{
			obj.pos = cur;
			calc_obj_vars(&obj, &data->player);
			*dst = obj;
			return ;
		}
	}
}
