/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:49:05 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:15:55 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		exit_with_message("mlx_init", "failed to initialize mlx");
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (data->mlx.win == NULL)
		exit_with_message("mlx_new_window", "failed to create window");
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (data->mlx.img == NULL)
		exit_with_message("mlx_new_image", "failed to create image");
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.size_line, &data->mlx.endian);
}
