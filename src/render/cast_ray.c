#include "render.h"


static t_collision	find_object(t_data *data, t_vector cur)
{
	t_vector_int	point;
	t_collision		obj;

	point = vector_to_int(cur);
	if (cur.x == floor(cur.x)) {
		obj.obj_type = data->map[point.y][point.x];
		obj.obj_facing_to = WEST;
		if (point.x - 1 >= 0 && obj.obj_type != WALL && !is_door(data, point))
		{
			obj.obj_type = data->map[point.y][point.x - 1];
			obj.obj_facing_to = EAST;
		}
	}
	else
	{
		obj.obj_type = data->map[point.y][point.x];
		obj.obj_facing_to = NORTH;
		if (point.y - 1 >= 0 && obj.obj_type != WALL && !is_door(data, point))
		{
			obj.obj_type = data->map[point.y - 1][point.x];
			obj.obj_facing_to = SOUTH;
		}
	}
	return (obj);
}

static void	calc_wall_x(t_collision *obj)
{
	if (obj->obj_facing_to == WEST)
		obj->wall_x = obj->pos.y - floor(obj->pos.y);
	else if (obj->obj_facing_to == EAST)
		obj->wall_x = ceil(obj->pos.y) - obj->pos.y;
	else if (obj->obj_facing_to == NORTH)
		obj->wall_x = obj->pos.x - floor(obj->pos.x);
	else
		obj->wall_x = ceil(obj->pos.x) - obj->pos.x;
	if (obj->wall_x >= 1)
		obj->wall_x -= 1;
	else if (obj->wall_x < 0)
		obj->wall_x += 1;
}

static void	calc_distance(t_collision *obj, t_player *player)
{
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
		if (cur.x <= 0 || data->map_width < cur.x || cur.y <= 0 || data->map_height < cur.y)
		{
			dst->obj_type = NONE;
			return ;
		}
		obj = find_object(data, cur);
		if (obj.obj_type == WALL || is_door(data, vector_to_int(cur)))
		{
			obj.pos = cur;
			calc_wall_x(&obj);
			calc_distance(&obj, &data->player);
			*dst = obj;
			return ;
		}
	}
}
