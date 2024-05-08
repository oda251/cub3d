/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 17:33:52 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "render.h"

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

int	key_hook(int keycode, t_data *data)
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
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
