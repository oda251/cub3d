/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:18 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 20:41:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = input_data(argc, argv);
	init_mlx(data);
	init_images(data);
	draw_floor_and_ceiling(data);
	convert_to_radian(data);//仮にここでラジアン表記に変更する
	draw_wall(data);
	set_hook(data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3D");
}