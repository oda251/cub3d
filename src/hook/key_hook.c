/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:21:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	key_hook(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		move_player(data, FORWARD);
	else if (keycode == KEY_A)
		move_player(data, LEFT);
	else if (keycode == KEY_S)
		move_player(data, BACKWARD);
	else if (keycode == KEY_D)
		move_player(data, RIGHT);
	else if (keycode == KEY_SPACE)
		switch_door(data);
	else if (keycode == KEY_LEFT)
		rotate_angle(data, LEFT);
	else if (keycode == KEY_RIGHT)
		rotate_angle(data, RIGHT);
	return (1);
}
