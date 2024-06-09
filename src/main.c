/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:18 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 02:25:35 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = input_data(argc, argv);
	init_mlx(data);
	//
	init_images(data);
	draw_floor_and_ceiling(data);
	//convert_to_radian(data);//仮にここでラジアン表記に変更する
	draw_wall(data);
	//
	render_minimap(data);
	set_hook(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_loop(data->mlx.mlx);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3D");
}