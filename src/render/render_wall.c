/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 06:01:45 by oda251            #+#    #+#             */
/*   Updated: 2024/08/23 06:14:06 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ray_angle = minus_angle(
				data->player.angle, VIEW_ANGLE * (0.5 - i / (double)WIN_WIDTH));
		angle_to_vector(ray_angle, &direction);
		cast_ray(data, view + i, direction);
		view[i].idx = i;
		i++;
	}
}

void	render_column(t_data *data, t_collision *col)
{
	size_t		scale;
	size_t		i;
	int			bottom;
	t_rgbo		color;

	scale = (WIN_HEIGHT / 1.2) / col->distance;
	if (scale <= 0 || (col->obj_type != WALL && !is_door(data, col->obj_pos)))
		return ;
	bottom = WIN_HEIGHT / 2 - scale / 2;
	i = 0;
	if (bottom < 0)
		i = -bottom;
	while (i < scale && bottom + i < WIN_HEIGHT)
	{
		color = get_color(data, col, (double) i / scale);
		put_pixel(&data->img_view, (t_vector_int){col->idx, bottom + i}, color);
		i++;
	}
}

static	t_rgbo	get_pixel(t_img *img, t_vector_int pos)
{
	int		pixel;

	if (img->endian == 0)
	{
		pixel = pos.y * img->size_line + pos.x * (img->bits_per_pixel / 8);
		return (*(t_rgbo *)(&img->addr[pixel]));
	}
	else
	{
		pixel = pos.y * img->size_line
			+ (pos.x + 1) * (img->bits_per_pixel / 8);
		return (img->addr[pixel - 1] << 24
			| img->addr[pixel - 2] << 16
			| img->addr[pixel - 3] << 8
			| img->addr[pixel - 4]);
	}
}

t_rgbo	get_color(t_data *data, t_collision *col, double wall_y)
{
	t_rgbo	color;
	t_img	*img;
	char	door_status;

	if (col->obj_type == DOOR)
	{
		img = &data->tex.img_door;
		door_status = data->door_map[col->obj_pos.y][col->obj_pos.x];
		color = get_pixel(img, (t_vector_int){
				col->wall_x * img->width,
				(img->height / MAX_DOOR_STATUS) * door_status
				+ wall_y * (img->height / MAX_DOOR_STATUS)
			});
	}
	else if (col->obj_type == WALL)
	{
		img = &data->tex.img[col->obj_facing_to];
		color = get_pixel(img,
				(t_vector_int){col->wall_x * img->width, wall_y * img->height});
	}
	return (color);
}
