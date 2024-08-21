/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:18 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:40:13 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "mlx.h"
# include "type.h"
# include "cub_error.h"
# include "init.h"
# include "hook.h"
# include "render.h"
// # include "draw.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = input_data(argc, argv);
	init_mlx(data);
	// draw_floor_and_ceiling(data);
	//convert_to_radian(data);//仮にここでラジアン表記に変更する
	// draw_wall(data);
	set_hook(data);
	get_current_ms(&data->time.tick_start);
	mlx_loop(data->mlx);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3d");
}