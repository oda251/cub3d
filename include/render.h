/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:30 by yoda              #+#    #+#             */
/*   Updated: 2024/08/23 07:00:02 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "type.h"
# include "cub_util.h"
# include <math.h>
# define VIEW_ANGLE 66

typedef struct s_collision
{
	int				idx;
	t_vector		pos;
	double			wall_x;
	t_vector_int	obj_pos;
	t_object_type	obj_type;
	t_direction		obj_facing_to;
	double			distance;
}				t_collision;

typedef struct s_ray
{
	t_vector	curr;
	t_vector	next;
	double		distance;
}				t_ray;

typedef struct s_dda
{
	t_ray		x_ray;
	t_ray		y_ray;
	t_vector	direction;
}				t_dda;

// calc_ray.c
void		cast_ray(t_data *data, t_collision *dst, t_vector direction);
// dda_handler.c
void		init_dda(t_data *data, t_dda *dda, t_vector *direction);
t_vector	proceed_dda(t_dda *dda);
// put_pixel.c
void		put_pixel(t_img *img, t_vector_int cur, t_rgbo color);
// render_background.c
void		render_background(t_data *data);
// render_minimap.c
void		render_minimap(t_data *data);
// render_wall.c
void		render_wall(t_data *data);

#endif
