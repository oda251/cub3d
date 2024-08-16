/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:02:58 by yoda              #+#    #+#             */
/*   Updated: 2024/08/17 03:25:53 by oda251           ###   ########.fr       */
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
	printf("angle: %d\n", data->player.angle);
	angle_to_vector(data->player.angle, &data->player.direction);
}
