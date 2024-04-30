/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:22:08 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 18:06:06 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

static t_vector_int	calc_dir(int angle)
{
	if (45 <= angle && angle < 135)
		return ((t_vector_int){0, -1});
	else if (135 <= angle && angle < 225)
		return ((t_vector_int){-1, 0});
	else if (225 <= angle && angle < 315)
		return ((t_vector_int){0, 1});
	else
		return ((t_vector_int){1, 0});
}

void	switch_door(t_data *data)
{
	t_vector_int	pos;
	t_vector_int	dir;

	pos.x = floor(data->player.position.x);
	pos.y = floor(data->player.position.y);
	dir = calc_dir(data->player.angle);
	if (data->map[pos.y + dir.y][pos.x + dir.x] == DOOR_CLOSED)
		data->map[pos.y + dir.y][pos.x + dir.x] = DOOR_OPEN;
	else if (data->map[pos.y + dir.y][pos.x + dir.x] == DOOR_OPEN)
		data->map[pos.y + dir.y][pos.x + dir.x] = DOOR_CLOSED;
}
