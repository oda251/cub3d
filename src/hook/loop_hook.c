/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:20:00 by oda251            #+#    #+#             */
/*   Updated: 2024/08/17 03:26:48 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "render.h"

static void	proceed_game(t_data *data)
{
	reflect_input(data);
	render_minimap(data);
}

int	loop_hook(t_data *data)
{
	t_ms	current;

	get_current_ms(&current);
	if (current - data->time.tick_start >= 1000 / FPS)
	{
		proceed_game(data);
		mlx_put_image_to_window(
			data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
		data->time.tick_start = current;
		data->time.ticks++;
	}
	return (1);
}
