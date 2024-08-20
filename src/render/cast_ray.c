#include "render.h"

void	cast_ray(t_data *data, t_collision *dst, t_vector direction)
{
	t_ray	ray_x;
	t_ray	ray_y;

	ray_x.vector = data->player.position;
	ray_x.distance = 0;
	ray_y.vector = data->player.position;
	ray_y.distance = 0;
	while (true)
	{
		if (ray_x.distance == ray_y.distance)
		{
			if (direction.x < direction.y)
			{
				*dst = (t_collision){ray_x.vector, WALL, EAST};
				return ;
			}
		}
	}
}

void	proceed_x(
	t_data *data, t_collision *dst, t_vector direction, t_ray *ray)
{
	
}