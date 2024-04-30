/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 21:21:36 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

static void	key_wasd(t_data *data, int keycode)
{
	data->key.w = false;
	data->key.a = false;
	data->key.s = false;
	data->key.d = false;
	if (keycode == KEY_W)
		data->key.w = true;
	else if (keycode == KEY_A)
		data->key.a = true;
	else if (keycode == KEY_S)
		data->key.s = true;
	else if (keycode == KEY_D)
		data->key.d = true;
}

static void	key_lr(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		data->key.r = false;
		data->key.l = true;
	}
	else if (keycode == KEY_RIGHT)
	{
		data->key.l = false;
		data->key.r = true;
	}
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
		key_wasd(data, keycode);
	else if (keycode == KEY_SPACE)
		switch_door(data);
	else if (keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		key_lr(data, keycode);
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
