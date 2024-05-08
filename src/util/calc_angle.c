/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:15:58 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:10:33 by yoda             ###   ########.fr       */
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

void	angle_to_vector(int angle, t_vector *vec)
{
	double radian = angle * (PI / 180.0);

	vec->x = cos(radian);
	vec->y = sin(radian);
}
