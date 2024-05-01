/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 19:21:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

static void	key_move(t_data *data, int keycode)
{
	if (keycode == KEY_W)
		move_player(data, FORWARD);
	else if (keycode == KEY_A)
		move_player(data, LEFT);
	else if (keycode == KEY_S)
		move_player(data, BACKWARD);
	else if (keycode == KEY_D)
		move_player(data, RIGHT);
}

static void	key_angle(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
		rotate_angle(data, LEFT);
	else if (keycode == KEY_RIGHT)
		rotate_angle(data, RIGHT);
}

int	key_hook_pressed(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D)
		key_move(data, keycode);
	else if (keycode == KEY_SPACE)
		switch_door(data);
	else if (keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		key_angle(data, keycode);
	return (1);
}

int	key_hook_released(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key.w = false;
	else if (keycode == KEY_A)
		data->key.a = false;
	else if (keycode == KEY_S)
		data->key.s = false;
	else if (keycode == KEY_D)
		data->key.d = false;
	else if (keycode == KEY_LEFT)
		data->key.l = false;
	else if (keycode == KEY_RIGHT)
		data->key.r = false;
	return (1);
}
