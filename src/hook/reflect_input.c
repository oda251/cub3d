/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:06:33 by oda251            #+#    #+#             */
/*   Updated: 2024/08/22 05:02:12 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	reflect_key_input(t_data *data);
void	reflect_mouse_input(t_data *data);

void	reflect_input(t_data *data)
{
	reflect_key_input(data);
	reflect_mouse_input(data);
}

void	reflect_key_input(t_data *data)
{
	if (data->key_input.w)
		move_player(data, FORWARD);
	if (data->key_input.a)
		move_player(data, LEFT);
	if (data->key_input.s)
		move_player(data, BACKWARD);
	if (data->key_input.d)
		move_player(data, RIGHT);
	if (data->key_input.left)
		rotate_angle(data, LEFT);
	if (data->key_input.right)
		rotate_angle(data, RIGHT);
}

void	reflect_mouse_input(t_data *data)
{
	if (data->mouse_prev.x == 0)
		data->mouse_prev = data->mouse;
	else if (data->mouse_prev.x != data->mouse.x)
	{
		data->player.angle = plus_angle(
				data->player.angle, data->mouse.x - data->mouse_prev.x);
		data->mouse_prev = data->mouse;
		printf("angle: %d\n", data->player.angle);
		angle_to_vector(data->player.angle, &data->player.direction);
	}
}
