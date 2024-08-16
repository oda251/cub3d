/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:15:58 by yoda              #+#    #+#             */
/*   Updated: 2024/08/17 04:45:53 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

int	plus_angle(int angle, int delta)
{
	angle += delta;
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	return (angle);
}

int	minus_angle(int angle, int delta)
{
	angle -= delta;
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	return (angle);
}

void	angle_to_vector(int angle, t_vector *vec)
{
	double	radian;

	radian = angle * (PI / 180.0);
	vec->x = cos(radian);
	vec->y = sin(radian);
}
