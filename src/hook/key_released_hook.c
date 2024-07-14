/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:20:41 by yoda              #+#    #+#             */
/*   Updated: 2024/07/14 23:03:24 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	key_released_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_input.w = false;
	else if (keycode == KEY_A)
		data->key_input.a = false;
	else if (keycode == KEY_S)
		data->key_input.s = false;
	else if (keycode == KEY_D)
		data->key_input.d = false;
	else if (keycode == KEY_SPACE)
		data->key_input.space = false;
	else if (keycode == KEY_LEFT)
		data->key_input.left = false;
	else if (keycode == KEY_RIGHT)
		data->key_input.right = false;
	return (1);
}
