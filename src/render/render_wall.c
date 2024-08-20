#include "render.h"

void	render_wall(t_data *data)
{
	t_collision	view[WIN_WIDTH];

	cast_rays(data, view);
}

void	cast_rays(t_data *data, t_collision *view)
{
	int			i;
	double		ray_angle;
	t_vector	direction;

	i = 0;
	while (i < VIEW_ANGLE)
	{
		ray_angle = minus_angle(data->player.angle + i, VIEW_ANGLE / 2);
		angle_to_vector(ray_angle, &direction);
		cast_ray(data, view + i, direction);
	}

}
