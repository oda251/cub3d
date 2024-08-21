#include "render.h"

void	cast_rays(t_data *data, t_collision *view);
void	render_column(t_data *data, t_collision *col);
t_rgbo	get_color(t_data *data, t_collision *col, double wall_y);

void	render_wall(t_data *data)
{
	t_collision	view[WIN_WIDTH];
	size_t		i;

	cast_rays(data, view);
	i = 0;
	while (i < WIN_WIDTH)
	{
		render_column(data, view + i);
		i++;
	}
}

void	cast_rays(t_data *data, t_collision *view)
{
	int			i;
	double		ray_angle;
	t_vector	direction;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_angle = minus_angle(data->player.angle, VIEW_ANGLE * (0.5 - i / (double)WIN_WIDTH));
		angle_to_vector(ray_angle, &direction);
		cast_ray(data, view + i, direction);
		view[i].idx = i;
		i++;
	}
}

void	render_column(t_data *data, t_collision *col)
{
	double		scale;
	size_t		i;
	int			cur;

	scale = WIN_HEIGHT / (1 * col->distance);
	if (scale <= 0 || (col->obj_type != WALL && col->obj_type != DOOR))
		return ;
	i = 0;
	cur = WIN_HEIGHT / 2 - scale / 2;
	if (cur < 0)
		cur = 0;
	while (i < scale && cur < WIN_HEIGHT)
	{
		t_rgbo	color;
		// color = get_color(data, col, i / scale);
		switch (col->obj_type)
		{
			case WALL:
				color = 0xFFFF00FF;
				break ;
			case DOOR:
				color = 0xFF000000 + 0x00FFFFFF / (data->door_map[(int)col->pos.y][(int)col->pos.x] + 1);
				break ;
			default:
				return ;
		}
		put_pixel(&data->img_view, (t_vector_int){col->idx, cur}, color);
		i++;
		cur++;
	}
}

t_rgbo	get_color(t_data *data, t_collision *col, double wall_y)
{

}
