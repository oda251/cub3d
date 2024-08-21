/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:15:58 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 04:37:10 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

double	plus_angle(double angle, double delta)
{
	angle += delta;
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	return (angle);
}

double	minus_angle(double angle, double delta)
{
	angle -= delta;
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	return (angle);
}

void	angle_to_vector(double angle, t_vector *vec)
{
	double	radian;

	radian = angle * (PI / 180.0);
	vec->x = cos(radian);
	vec->y = sin(radian);
}
