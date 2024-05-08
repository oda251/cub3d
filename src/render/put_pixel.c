/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:50:06 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 17:16:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(t_data *data, t_vector_int cur, t_rgb color)
{
	const t_mlx	mlx = data->mlx;
	const int	pixel = cur.y * mlx.size_line + cur.x * (mlx.bits_per_pixel / 8);
	
	if (mlx.endian == 1)
	{
		mlx.addr[pixel + 0] = color.r;
		mlx.addr[pixel + 1] = color.g;
		mlx.addr[pixel + 2] = color.b;
	}
	else
	{
		mlx.addr[pixel + 0] = color.b;
		mlx.addr[pixel + 1] = color.g;
		mlx.addr[pixel + 2] = color.r;
	}
}
