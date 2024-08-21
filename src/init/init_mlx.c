/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:49:05 by yoda              #+#    #+#             */
/*   Updated: 2024/08/21 23:08:41 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_image(t_data *data, t_img *img, size_t width, size_t height);

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit_with_message("mlx_init", "failed to initialize mlx");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (data->win == NULL)
		exit_with_message("mlx_new_window", "failed to create window");
	init_image(data, &data->img_view, WIN_WIDTH, WIN_HEIGHT);
	init_image(data, &data->img_minimap, MINIMAP_SIZE * MINIMAP_TILE_SIZE, MINIMAP_SIZE * MINIMAP_TILE_SIZE);
}

void	init_image(t_data *data, t_img *img, size_t width, size_t height)
{
	img->img = mlx_new_image(data->mlx, width, height);
	if (img->img == NULL)
		exit_with_message("mlx_new_image", "failed to create image");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}
