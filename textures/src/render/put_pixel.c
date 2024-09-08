/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:50:06 by yoda              #+#    #+#             */
/*   Updated: 2024/08/23 06:07:06 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(t_img *img, t_vector_int cur, t_rgbo color)
{
	int			pixel;

	if (img->endian == 0)
	{
		pixel = cur.y * img->size_line + cur.x * (img->bits_per_pixel / 8);
		*(t_rgbo *)(&img->addr[pixel]) = color;
	}
	else
	{
		pixel = cur.y * img->size_line
			+ (cur.x + 1) * (img->bits_per_pixel / 8);
		img->addr[pixel - 1] = color;
		img->addr[pixel - 2] = color >> 24;
		img->addr[pixel - 3] = color >> 16;
		img->addr[pixel - 4] = color >> 8;
	}
}
