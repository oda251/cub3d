/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2024/07/14 22:45:11 by oda251           ###   ########.fr       */
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
	return (1);
}
