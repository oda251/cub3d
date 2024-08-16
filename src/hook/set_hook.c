/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:37:47 by yoda              #+#    #+#             */
/*   Updated: 2024/08/17 03:26:15 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	set_hook(t_data *data)
{
	mlx_hook(data->mlx.win,
		DestroyNotify, NoEventMask, exit_game, EXIT_SUCCESS);
	mlx_hook(data->mlx.win,
		KeyPress, KeyPressMask, key_pressed_hook, data);
	mlx_hook(data->mlx.win,
		KeyRelease, KeyReleaseMask, key_released_hook, data);
	mlx_hook(data->mlx.win,
		MotionNotify, PointerMotionMask, mouse_hook, data);
	mlx_loop_hook(data->mlx.mlx, loop_hook, data);
}
