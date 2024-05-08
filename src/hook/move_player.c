/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:15 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:09:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	move_player(t_data *data, t_direction direction)
{
	t_vector	next_pos;
	int			move_angle;
	t_vector	move_vec;

	move_angle = plus_angle(data->player.angle, 180);
	if (direction == BACKWARD)
		move_angle = plus_angle(data->player.angle, 0);
	else if (direction == LEFT)
		move_angle = plus_angle(data->player.angle, 90);
	else if (direction == RIGHT)
		move_angle = plus_angle(data->player.angle, -90);
	angle_to_vector(move_angle, &move_vec);
	next_pos.x = data->player.position.x + move_vec.x * MOVE_RATE;
	next_pos.y = data->player.position.y + move_vec.y * MOVE_RATE;
	if (data->map[(int)next_pos.y][(int)next_pos.x] != WALL
		&& data->map[(int)next_pos.y][(int)next_pos.x] != DOOR_CLOSED)
		data->player.position = next_pos;
	else
		error_message(NULL, "Hit the wall.");
	printf("Player position: (%f, %f)\n", data->player.position.x, data->player.position.y);
}
