/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:30 by yoda              #+#    #+#             */
/*   Updated: 2024/08/20 03:12:18 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "type.h"
# define VIEW_ANGLE 120

typedef enum	e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}				t_direction;

typedef struct	s_collision
{
	t_vector		pos;
	t_object_type	obj_type;
	t_direction		obj_facing_to;
}				t_collision;

typedef struct	s_ray
{
	t_vector	vector;
	double		distance;
}				t_ray;

// calc_ray.c
void	cast_ray(t_data *data, t_collision *dst, t_vector direction);
// put_pixel.c
void	put_pixel(t_data *data, t_vector_int cur, t_rgbo color);
// render_minimap.c
void	render_minimap(t_data *data);

#endif
