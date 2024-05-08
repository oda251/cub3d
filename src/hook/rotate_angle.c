/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:02:58 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:14:36 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_angle(t_data *data, t_direction direction)
{
	if (direction == LEFT)
		data->player.angle = plus_angle(data->player.angle, -ROTATE_RATE);
	else if (direction == RIGHT)
		data->player.angle = plus_angle(data->player.angle, ROTATE_RATE);
	else
		exit_with_message("rotate_angle", "Invalid direction.");
	angle_to_vector(data->player.angle, &data->player.direction);
}
