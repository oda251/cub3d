/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:34:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	mouse_hook(int x, int y, t_data *data)
{
	(void) y;
	if (data->mouse.x != x)
		data->player.angle += (data->mouse.x - x) * MOUSE_SENSITIVITY;
	data->mouse.x = x;
	data->mouse.y = y;
	return (EXIT_SUCCESS);
}
