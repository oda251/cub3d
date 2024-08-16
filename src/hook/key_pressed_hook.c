/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/08/17 03:20:03 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

static void	key_move(t_data *data, int keycode)
{
	if (keycode == KEY_W)
	{
		data->key_input.w = true;
		data->key_input.s = false;
	}
	else if (keycode == KEY_A)
	{
		data->key_input.a = true;
		data->key_input.d = false;
	}
	else if (keycode == KEY_S)
	{
		data->key_input.s = true;
		data->key_input.w = false;
	}
	else if (keycode == KEY_D)
	{
		data->key_input.d = true;
		data->key_input.a = false;
	}
	else if (keycode == KEY_SPACE)
		data->key_input.space = true;
}

static void	key_angle(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
		data->key_input.left = true;
	else if (keycode == KEY_RIGHT)
		data->key_input.right = true;
}

int	key_pressed_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		key_angle(data, keycode);
	else
		key_move(data, keycode);
	return (1);
}
