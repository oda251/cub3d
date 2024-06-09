/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:50:06 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 02:24:56 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

void	put_pixel(t_data *data, t_vector_int cur, t_rgbo color)
{
	const	t_mlx	mlx = data->mlx;
	int		pixel;
	
	if (mlx.endian == 1)
	{
		pixel = cur.y * mlx.size_line + cur.x * (mlx.bits_per_pixel / 8);
		*(t_rgbo *)(&mlx.addr[pixel]) = color;
	}
	else
	{
		pixel = cur.y * mlx.size_line + (cur.x + 1) * (mlx.bits_per_pixel / 8);
		mlx.addr[pixel - 1] = color;
		mlx.addr[pixel - 2] = color >> 24;
		mlx.addr[pixel - 3] = color >> 16;
		mlx.addr[pixel - 4] = color >> 8;
	}
}
