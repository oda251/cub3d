/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:37:47 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:43:07 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	set_hook(t_data *data)
{
	mlx_hook(data->win,
		DestroyNotify, NoEventMask, exit_game, EXIT_SUCCESS);
	mlx_hook(data->win,
		KeyPress, KeyPressMask, key_pressed_hook, data);
	mlx_hook(data->win,
		KeyRelease, KeyReleaseMask, key_released_hook, data);
	mlx_hook(data->win,
		MotionNotify, PointerMotionMask, mouse_hook, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
}
