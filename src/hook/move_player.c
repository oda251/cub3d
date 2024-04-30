/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:15 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:20:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	move_player(t_data *data, t_direction direction)
{
	t_vector		next_pos;

	if (direction == FORWARD)
		next_pos = (t_vector){data->player.position.x + data->player.direction.x * MOVE_RATE,
			data->player.position.y + data->player.direction.y * MOVE_RATE};
	else if (direction == BACKWARD)
		next_pos = (t_vector){data->player.position.x - data->player.direction.x * MOVE_RATE,
			data->player.position.y - data->player.direction.y * MOVE_RATE};
	else if (direction == LEFT)
		next_pos = (t_vector){data->player.position.x - data->player.direction.y * MOVE_RATE,
			data->player.position.y + data->player.direction.x * MOVE_RATE};
	else if (direction == RIGHT)
		next_pos = (t_vector){data->player.position.x + data->player.direction.y * MOVE_RATE,
			data->player.position.y - data->player.direction.x * MOVE_RATE};
	if (data->map[(int)next_pos.y][(int)next_pos.x] != WALL
		&& data->map[(int)next_pos.y][(int)next_pos.x] != DOOR_CLOSED)
		data->player.position = next_pos;
	else
		error_message(NULL, "Hit the wall.");
	printf("Player position: (%f, %f)\n", data->player.position.x, data->player.position.y);
}
